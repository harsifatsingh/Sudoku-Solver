#include "sudoku.h"

int **createPuzzle()
{
    int **puzzle = malloc(9 * sizeof *puzzle);

    int arr[9][9] = {
        {0, 1, 9, 0, 0, 2, 0, 0, 0},
        {4, 7, 0, 6, 9, 0, 0, 0, 1},
        {0, 0, 0, 4, 0, 0, 0, 9, 0},
        {8, 9, 4, 0, 5, 7, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 1, 9, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 5, 0, 0, 0, 6, 0, 0, 0},
        {6, 0, 0, 2, 8, 0, 7, 0, 9},
        {0, 0, 0, 1, 0, 0, 8, 6, 0}};

    for (int i = 0; i < 9; i++)
    {
        puzzle[i] = malloc(sizeof(int *) * 9);

        for (int j = 0; j < 9; j++)
        {
            puzzle[i][j] = arr[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(int **puzzle)
{
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int val = puzzle[i][j];
            if (val == 0)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", puzzle[i][j]);
            }
            if ((j + 1) % 3 == 0 && j != 8)
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != 8)
        {
            printf("---------------------\n");
        }
    }
    printf("\n");
}