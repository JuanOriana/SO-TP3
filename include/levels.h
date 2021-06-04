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
#define LEVEL_COUNT 12

int level1(FILE *clientFile, char *buff, char *ans);
int level2(FILE *clientFile, char *buff, char *ans);
int level3(FILE *clientFile, char *buff, char *ans);
int level4(FILE *clientFile, char *buff, char *ans);
int level5(FILE *clientFile, char *buff, char *ans);
int level6(FILE *clientFile, char *buff, char *ans);
int level7(FILE *clientFile, char *buff, char *ans);
int level8(FILE *clientFile, char *buff, char *ans);
int level9(FILE *clientFile, char *buff, char *ans);
int level10(FILE *clientFile, char *buff, char *ans);
int level11(FILE *clientFile, char *buff, char *ans);
int level12(FILE *clientFile, char *buff, char *ans);

#endif