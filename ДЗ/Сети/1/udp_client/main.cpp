#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#include <unistd.h> /* Needed for close() */

const int BUFFER_SIZE = 256;
char buffer[BUFFER_SIZE];
char message[BUFFER_SIZE];

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <ip_addr> <port> " << std::endl;
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    const int port ={ std::stoi(argv[2]) };

    auto sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock == -1)
    {
        std::cerr << strerror_r(errno, &buffer[0], BUFFER_SIZE) << std::endl;
        return EXIT_FAILURE;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
//    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(addr.sin_family, ip, &(addr.sin_addr));

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        std::cerr << strerror_r(errno, &buffer[0], BUFFER_SIZE) << std::endl;
        close(sock);

        return EXIT_FAILURE;
    }

    while(strcmp(message, "exit") != 0)
    {
        std::cout << "<< ";
        std::cin >> message;

        send(sock, message, sizeof(message), 0);
        recv(sock, buffer, sizeof(message), 0);

        std::cout << ">> " << buffer << '\n';
    }
    close(sock);

    return EXIT_SUCCESS;
}
