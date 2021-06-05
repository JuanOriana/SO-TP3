// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_LEN 256

int main(int argc, char *argv[])
{
    int socketFd;
    struct sockaddr_in serv_addr;

    char buffer[BUFF_LEN];

    if (argc != 3)
    {
        fprintf(stderr, "usage %s address port\n", argv[0]);
        exit(0);
    }

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        printf("inet_pton: invalid address");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    memset(buffer, 0, BUFF_LEN);
    while (fgets(buffer, BUFF_LEN - 1, stdin) != NULL)
    {
        /* Send message to the server */
        int len = write(socketFd, buffer, BUFF_LEN);

        if (len < 0)
        {
            perror("write");
            exit(1);
        }

        memset(buffer, 0, BUFF_LEN);
    }
    return 0;
}
