#include <stdio.h>
#include <stdlib.h>

typedef struct Box
{
} Box;

typedef struct Square
{
    int number;
    char possible;
    Box *box;
    int row;
    int column;
} Square;

int **createPuzzle();
void printPuzzle(int **puzzle);