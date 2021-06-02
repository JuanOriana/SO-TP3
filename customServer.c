// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "include/levels.h"

#define PORT 8080
#define ADDRESS "0.0.0.0"

static Level levelArray[] = {
    {level1, "entendido\n"},
    {level2, "itba\n"},
    {level3, "M4GFKZ289aku\n"}

};

static void beginCTF(int clientFd);

int main()
{
    int serverFd, clientFd, opt = 1;
    struct sockaddr_in address;
    int addrLen = sizeof(address);

    serverFd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

    if (serverFd == 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) != 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_aton(ADDRESS, &address.sin_addr);

    if ((bind(serverFd, (struct sockaddr *)&address, addrLen)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if ((listen(serverFd, 5)) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    clientFd = accept(serverFd, (struct sockaddr *)&address, (socklen_t *)&addrLen);
    if (clientFd < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    beginCTF(clientFd);

    close(serverFd);
}

static void beginCTF(int clientFd)
{
    int retVal = 0, level = 0;
    FILE *clientFile = fdopen(clientFd, "r");
    char *response = malloc(sizeof(char) * CAP);

    while (level < LEVEL_COUNT && retVal != -1)
    {
        Level currLevel = levelArray[level];
        printf("\033[1;1H\033[2J");
        memset(response, 0, CAP);

        printf("------------- DESAFIO -------------\n");
        if ((retVal = currLevel.levelFun(clientFile, response, currLevel.ans)) == 1)
        {
            level++;
        }
        else
        {
            printf("Respuesta incorrecta: %s\n", response);
            sleep(2);
        }
    }

    free(response);

    if (retVal == -1)
    {
        return;
    }

    printf("\033[1;1H\033[2J");

    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}