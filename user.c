// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int socketFd, portno, n;
    struct sockdah_in serv_addr;
    struct hostent *server;

    char buffer[256];

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR socket");
        exit(1);
    }

    if ((server = gethostbyname(argv[1])) == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Ingrese la respuesta: ");
    memset(buffer, 0, 256);
    while (fgets(buffer, 255, stdin) != NULL)
    {
        /* Send message to the server */
        n = write(socketFd, buffer, strlen(buffer));

        if (n < 0)
        {
            perror("write");
            exit(1);
        }

        memset(buffer, 0, 256);

        printf("Ingrese la respuesta: ");
    }
    return 0;
}