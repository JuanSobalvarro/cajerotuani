#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

/*
    Returns a pointer to a string of
    a size depending on the input.
    Where the input can be any type of file
    and the lenofS is a pointer to a size_int to save
    string lenght.
*/
char *inputString(FILE* fp, size_t *lenofS)
{
    // string pointer
    char *str;
    int ch;
    size_t len = 0;
    //size_t size = 10;

    // re allocalize memory to our necessary size
    str = realloc(NULL, sizeof(*str) * len);

    // if couldnt reallocate memory return str
    if (!str)
    {
        return str;
    }

    // fgetc returns a readed unsigned char in the file casted to a int. EOF means end of file
    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str[len++] = ch;
        str = realloc(str, sizeof(*str)*(len));
        if(!str)
        {
            return str;
        }
    }
    str[len++] = '\0';

    *lenofS = len;

    return realloc(str, sizeof(*str)*len);
}

/*
    Check if a string is a real number 
*/
int isNum(char *s)
{
    char *str;
    str = s;

    char c;
    int point_count = 0;

    // if the first digit is not a minus sign or a number is no t anumber
    if((c = *(str++)) != '-' &&  !(c >= '0' && c <= '9'))
    {
        //printf("\nsign\n");
        return 0;
    }

    while ((c = *(str++)) != '\0')
    {
        if (c == '.')
        {
            if (++point_count > 1)
            {
                //printf("\npoint\n");
                return 0;
            } 
        }
        else if (!(c >= '0' && c <= '9'))
        {
            //printf("\ndigit\n");
            return 0;
        }
    }

    return 1;
}

void *copymemory(void *dest, const void *src, size_t count)
{
    char *tmp = dest;
    const char *s = src;

    while (count != 0)
    {
        *tmp++ = *s++;
        --count;
    }
    return dest;
}

int strtoint(char *s)
{
    char c;
    char *str;
    str = s;
    int count;
    int num = 0;

    while ((c = *(str++)) != '\0')
    {
        if (!(c >= '0' && c <= '9'))
        {
            return 0;
        }
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        num += (s[i]-48) * pow(10, count-i);
    }

    return num;
}

/*
    Read CSV file and returns an array of 
*/
char **readCSV(FILE *fp)
{
    return NULL;
}

/*
    Input a pin in pin format (it doesnt show the characters only the symbol)
*/
void pinInput(char *str, char symbol, int size)
{
    char *s;
    s = str;

    for (int i = 0; i < size; i++)
    {
        *(s++) = getch();
        putchar(symbol);    
    }
    *s = '\0';
}

int compStr(char *str1, char *str)
{
    char *s1, *s2;
    s1 = str1;
    s2 = str;
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*(s1++) != *(s2++))
        {
            return 0;
        }
    }

    return 1;
}