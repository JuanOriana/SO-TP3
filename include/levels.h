#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>

typedef int (*LevelFun)(FILE *clientFile, char *buff, char *ans);

typedef struct Level
{
    LevelFun levelFun;
    char *ans;
} Level;

#define CAP 100
#define LEVEL_COUNT 4

int level1(FILE *clientFile, char *buff, char *ans);
int level2(FILE *clientFile, char *buff, char *ans);
int level3(FILE *clientFile, char *buff, char *ans);
int level4(FILE *clientFile, char *buff, char *ans);

#endif