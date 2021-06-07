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
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

#define PORT 8080
#define ADDRESS "0.0.0.0"

char *easterEgg = " _______________________\n< ESTO ES UN EASTER_EGG >\n -----------------------\n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||";

static Level levelArray[] = {
    {introductionChallenge, "entendido\n", "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?"},
    {pagerChallenge, "itba\n", "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?"},
    {photoChallenge, "M4GFKZ289aku\n", "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?"},
    {ebadfChallenge, "fk3wfLCm3QvS\n", "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?"},
    {stringsChallenge, "too_easy\n", "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?"},
    {sectionChallenge, ".RUN_ME\n", "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?"},
    {filterChallenge, "K5n2UFfpFMUN\n", "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?"},
    {incognitoChallenge, "BUmyYq5XxXGt\n", "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?"},
    {latexChallenge, "u^v\n", "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?"},
    {quineChallenge, "chin_chu_lan_cha\n", "¿Cuáles son las características del protocolo SCTP?"},
    {gdbChallenge, "gdb_rules\n", "¿Qué es un RFC?"},
    {randomChallenge, "normal\n", "¿Fue divertido?"}

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

    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) != 0)
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

    return 0;
}

static void beginCTF(int clientFd)
{
    int retVal = 0, level = 0;
    FILE *clientFile = fdopen(clientFd, "r");
    char *response = malloc(sizeof(char) * CAP);
    if (response == NULL)
    {
        return;
    }

    srand(time(0));

    while (level < LEVEL_COUNT && retVal != -1)
    {
        Level currLevel = levelArray[level];
        printf("\033[1;1H\033[2J");

        memset(response, 0, CAP);

        printf("------------- DESAFIO -------------\n");
        if ((retVal = currLevel.levelFun(clientFile, response, currLevel.invQuest, currLevel.ans)) == 1)
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
    fclose(clientFile);

    if (retVal == -1)
    {
        return;
    }

    printf("\033[1;1H\033[2J");

    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}