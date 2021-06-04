#include "include/levels.h"
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#define ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING 42
#define RAND_OFFSET 6
#define FIRST_PRINTABLE 32
#define LAST_PRINTABLE 126

int too_easy = ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING;

static void gdbme()
{
    if (getpid() == 0x12345678)
    {
        printf("La respuesta es: gdb_rules\n\n");
    }
}

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

int level7(FILE *clientFile, char *buff, char *ans)
{

    printf("Filter error\n");

    char completeAns[64] = "La respuesta es :";
    strcat(completeAns, ans);

    int i = 0;
    while (completeAns[i])
    {
        int fd = rand() % (RAND_OFFSET - STDOUT_FILENO + 1) + STDOUT_FILENO;

        if (fd == STDOUT_FILENO && completeAns[i])
        {
            write(STDOUT_FILENO, completeAns + i++, 1);
        }
        else
        {
            char c = (char)(rand() % (FIRST_PRINTABLE - LAST_PRINTABLE + 1) + FIRST_PRINTABLE);
            write(STDERR_FILENO, &c, 1);
        }
    }

    return inputAnalyzer(clientFile, buff, ans);
}

int level8(FILE *clientFile, char *buff, char *ans)
{
    printf("¿?\n\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level9(FILE *clientFile, char *buff, char *ans)
{
    printf(
        "Latexme\n\n"
        "Si\n"
        "\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n"
        "entonces\n"
        "y =\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level10(FILE *clientFile, char *buff, char *ans)
{

    int existsQuine, isValidQuine;
    printf("quine.\n\n");

    existsQuine = system("gcc quine.c -o quine");

    if (existsQuine == 0)
    {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
        isValidQuine = system("./quine | diff - quine.c");
        if (isValidQuine == 0)
        {
            printf("La respuesta es chin_chu_lan_cha\n\n");
        }
        else
        {
            printf("\n%s\n", "diff encontró diferencias.");
        }
    }
    else
        printf("\n\n ENTER para reintentar.\n\n");

    return inputAnalyzer(clientFile, buff, ans);
}

int level11(FILE *clientFile, char *buff, char *ans)
{
    printf("b gdbme y encontrá el valor mágico ENTER para reintentar.\n\n");

    gdbme();

    return inputAnalyzer(clientFile, buff, ans);
}