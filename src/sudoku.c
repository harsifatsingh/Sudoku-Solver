#include "sudoku.h"

short int UNSOLVED = 81;
int POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
    int **puzzle = createPuzzle();
    Sudoku *sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);
    while (UNSOLVED > 0)
    {
        checkPuzzle(sudoku->squares, sudoku->boxes);
        printPuzzle(sudoku->squares);
    }
    printPuzzle(sudoku->squares);

    return 0;
}