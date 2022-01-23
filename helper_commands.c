#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include <ctype.h>

char isnumber(char *n)
{
    int i = 0;
    if (n[0] == '-') i = 1;
    while(n[i] != '\n' && n[i] != '\0')
    {
        if (!isdigit(n[i]))
        {
            return 0;
        }
        i++;
    }
    if (n[0] == '-' && i == 1) return 0;
    return 1;
}

void reset_pawns(int boardsize, position *white, position *black)
{
    white->i = 0;
    white->j = boardsize / 2;
    black->j = boardsize / 2;
    black->i = boardsize - 1;
}

void swap_boardsize(char* p, int *boardsize, int *prev_boardsize)
{
    if (*boardsize > 0) 
    {
        *prev_boardsize = *boardsize;
        printf("=");
        fflush(stdout);
    }
    
    *boardsize = atoi(p);
}

char is_x_available(char hor, position white)
{
    if (hor >= 'A' && hor < (white.j + 'A'))
    {
        return 1;
    }
    else if (hor >= 'a' && hor < (white.j + 'a'))
    {
        return 1;
    }
    return 0;
}

char is_y_availabe(char hor, position black)
{
    if (hor >= 0 && hor < black.i)
    {
        return 1;
    }
    return 0;
}

position *check_color(char *p, position *black, position *white)
{
    // function returns 1 for white, 0 for black and -1 for unknown color

    if (strcmp(p, "white") == 0) return white;
    else if (strcmp(p, "w") == 0) return white;
    else if (strcmp(p, "black") == 0) return black;
    else if (strcmp(p, "b") == 0) return white;
    else return NULL;
}

char check_orientation(char *orientation)
{
    // function returns 1 for horizontal, 0 for vertical and -1 for uknown orientation

}

char arguments(char *buff)
{
    char arg = 1;
    char y = 0;
    int i = 0;
    while (buff[i] != '\0')
    {
        if (buff[i] == ' ') arg ++;
        else if (buff[i] != ' ' && buff[i] != '\t') y = 1;
        i++;
    }
    if (y = 0) return -1;
    return arg;
}