#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>

typedef int (*LevelFun)(FILE *clientFile, char *buff, char *invQuest, char *ans);

typedef struct Level
{
    LevelFun levelFun;
    char *ans;
    char *invQuest;
} Level;

#define CAP 100
#define LEVEL_COUNT 12

int introductionChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int pagerChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int photoChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int ebadfChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int stringsChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int sectionChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int filterChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int incognitoChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int latexChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int quineChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int gdbChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);
int randomChallenge(FILE *clientFile, char *buff, char *invQuest, char *ans);

#endif