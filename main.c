#include <stdio.h>

#include "cajero.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: main.exe accounstsPath.csv movementsPath.csv tempPath.csv\n");
        return 0;
    } 
    CAJERO *caj = initCAJERO(argv[1], argv[2], argv[3]);

    execCAJERO(caj);

    return 0;
}