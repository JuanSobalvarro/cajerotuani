#ifndef CAJERO_H
#define CAJERO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "utilities.h"

typedef struct tm local;

typedef struct ACCOUNT
{
    char id[5];
    char pin[5];
    char name[10];
    int balance;
} ACCOUNT;

typedef struct CAJERO
{
    ACCOUNT *account;
    int bills[4]; // quantity of each bills in the atm
    int billsVal[4]; // values of bills
    char *accountsPath; // csv path of accounts
    char *movementsPath; // csv path of movements
    char *tempPath;
} CAJERO;

CAJERO *initCAJERO(char *accPATH, char *movPATH, char *tempPath);

void *execCAJERO(CAJERO *caj);

#endif
