#include "include/levels.h"
#include <string.h>
#include <unistd.h>

#define ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING 42

int too_easy = ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING;

static int inputAnalyzer(FILE *clientFile, char *buff, char *ans)
{
    if (fgets(buff, CAP, clientFile) == NULL)
        return -1;

    return strcmp(buff, ans) == 0;
}

int level1(FILE *clientFile, char *buff, char *ans)
{
    printf(
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel."
        "Además tendrán que investigar otras preguntas para responder durante la defensa."
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level2(FILE *clientFile, char *buff, char *ans)
{
    printf(
        "The Wire S1E5\n"
        "5295 888 6288\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level3(FILE *clientFile, char *buff, char *ans)
{
    printf("https://ibb.co/tc0Hb6w\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level4(FILE *clientFile, char *buff, char *ans)
{
    if (write(420, "................................La respuesta es fk3wfLCm3QvS\n", 61) == -1)
    {
        perror("write");
    }

    printf("EBADF...\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level5(FILE *clientFile, char *buff, char *ans)
{

    printf("respuesta = strings:129\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level6(FILE *clientFile, char *buff, char *ans)
{
    printf(".debug_abbrev .debug_line .debug_str ? .symtab .strtab. .shstrtab\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}