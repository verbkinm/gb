#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
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

int ping(const char* ip, const ulong timeout, ulong* reply_time)
{
    if (ip == NULL || timeout == 0)
        return _err_failed;

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
    if (sendto(sock, &ping_pkt, sizeof(ping_pkt_t), 0, (sockaddr*)&to_addr, socklen) <= 0)
    {
        close(sock);
        return _err_failed;
    }

    ip_pkt_t ip_pkt;
    sockaddr_in from_addr;
    recvfrom(sock, &ip_pkt, sizeof(ip_pkt_t), 0, (struct sockaddr*)&from_addr, &socklen);

    close(sock);
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
