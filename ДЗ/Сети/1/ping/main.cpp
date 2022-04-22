#include <iostream>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <thread>
#include <mutex>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>

#define PING_PKT_DATA_SZ    64
#define _err_ok             0
#define _err_failed         -1
#define _err_timeout        1

typedef struct
{
    struct icmp hdr;
    char data[PING_PKT_DATA_SZ];
} ping_pkt_t;

typedef struct
{
    struct ip ip_hdr;
    ping_pkt_t ping_pkt;
} ip_pkt_t;

static void prepare_icmp_pkt(ping_pkt_t *ping_pkt);
static ushort checksum(void *b, int len);
int ping(const char* ip, ulong* reply_time);
void waitRecv(int sock, ip_pkt_t &buf, size_t len, int flags, sockaddr_in &src_addr, socklen_t &addrlen);

std::mutex mutex;
bool dataRecive = false;

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <host>\n";
        return EXIT_FAILURE;
    }

    const char* const host = argv[1];
    unsigned long reply_time = 0;

    const int result = ping(host, &reply_time);

    if (result == -1)
    {
        std::cout << "Host is not available.\n";
        return EXIT_FAILURE;
    }
    else if (result == 1)
        std::cout << "Timeout.\n";
    else
        std::cout << "Ping host=" << host << " time=" << reply_time << " ms\n";

    return EXIT_SUCCESS;
}

int ping(const char* ip, ulong* reply_time)
{
    ping_pkt_t ping_pkt;
    prepare_icmp_pkt(&ping_pkt);

    sockaddr_in to_addr;
    to_addr.sin_family = AF_INET;
    if (!inet_aton(ip, (in_addr*)&to_addr.sin_addr.s_addr))
    {
        std::cout << "inet_aton\n";
        return _err_failed;
    }

    if (!strcmp(ip, "255.255.255.255") || to_addr.sin_addr.s_addr == 0xFFFFFFFF)
        return _err_failed;

    const int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1)
    {
        std::cout << "socket() " << strerror(errno) << '\n';
        return _err_failed;
    }

    socklen_t socklen = sizeof(sockaddr_in);

    auto start = std::chrono::steady_clock::now();
    if (sendto(sock, &ping_pkt, sizeof(ping_pkt_t), 0, (sockaddr*)&to_addr, socklen) <= 0)
    {
        close(sock);
        return _err_failed;
    }

    ip_pkt_t ip_pkt;
    sockaddr_in from_addr;

//    std::thread t(waitRecv, sock, std::ref(ip_pkt), sizeof(ip_pkt_t), 0, std::ref(from_addr), std::ref(socklen));
//    t.detach();
    recvfrom(sock, &ip_pkt, sizeof(ip_pkt_t), 0, (struct sockaddr*)&from_addr, &socklen);

//    for (uint i = 0; i < 5000; i++)
//    {
//        std::lock_guard lg(mutex);
//        if (dataRecive)
//            break;

//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
//    }

    auto end = std::chrono::steady_clock::now();
    *reply_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    close(sock);

//    if (dataRecive == false)
//        return _err_timeout;

    return 0;
}

static void prepare_icmp_pkt(ping_pkt_t *ping_pkt)
{
    memset(ping_pkt, 0, sizeof(ping_pkt_t));

    int i = 0;
    for (; i < sizeof(ping_pkt->data) - 1; ++i)
        ping_pkt->data[i] = i + 'a';

    ping_pkt->data[i] = 0;

    srand(time(0));
    const short random_id = rand();
    ping_pkt->hdr.icmp_type = ICMP_ECHO;
    ping_pkt->hdr.icmp_hun.ih_idseq.icd_id = random_id;
    ping_pkt->hdr.icmp_hun.ih_idseq.icd_seq = 0;
    ping_pkt->hdr.icmp_cksum = checksum(ping_pkt, sizeof(ping_pkt_t));
}

static ushort checksum(void *b, int len)
{
    ushort *buf = (ushort*)b;
    uint sum=0;
    ushort result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void waitRecv(int sock, ip_pkt_t &buf, size_t len, int flags, sockaddr_in &src_addr, socklen_t &addrlen)
{
    recvfrom(sock, &buf, len, flags, (struct sockaddr*)&src_addr, &addrlen);

    std::lock_guard lg(mutex);
    dataRecive = true;
}
