#include "sudoku.h"

short int UNSOLVED = 81;
int POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
    int progress;

    int **puzzle = createPuzzle();
    Sudoku *sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);
    while (UNSOLVED > 0)
    {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (!progress)
            break;
    }

    printPuzzle(sudoku->squares);
    if (UNSOLVED > 0)
    {
        printf("Switching to backtracking...\n");
        if (!backtrackSolve(sudoku))
        {
            printf("No solution found.\n");
            return 1;
        }
    }
    printPuzzle(sudoku->squares);

    return 0;
}