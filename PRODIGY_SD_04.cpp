#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function declarations
bool solveSudoku(vector<vector<int>>& grid);
vector<int> findEmptyCell(const vector<vector<int>>& grid);
bool isValidMove(const vector<vector<int>>& grid, int row, int col, int num);
bool usedInRow(const vector<vector<int>>& grid, int row, int num);
bool usedInCol(const vector<vector<int>>& grid, int col, int num);
bool usedInBox(const vector<vector<int>>& grid, int boxStartRow, int boxStartCol, int num);
void printSudoku(const vector<vector<int>>& grid);

int main() {
    vector<vector<int>> sudokuGrid(SIZE, vector<int>(SIZE));

    cout << "Enter the Sudoku puzzle (9x9 grid). Use 0 for empty cells:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> sudokuGrid[i][j];
        }
    }

    if (solveSudoku(sudokuGrid)) {
        cout << "Sudoku solved successfully:" << endl;
        printSudoku(sudokuGrid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}

bool solveSudoku(vector<vector<int>>& grid) {
    vector<int> emptyCell = findEmptyCell(grid);

    if (emptyCell.empty()) {
        return true; // No empty cell found, puzzle is solved
    }

    int row = emptyCell[0];
    int col = emptyCell[1];

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; // Backtrack
        }
    }

    return false; // No valid number found, need to backtrack
}

vector<int> findEmptyCell(const vector<vector<int>>& grid) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                return {row, col};
            }
        }
    }
    return {}; // No empty cell found
}

bool isValidMove(const vector<vector<int>>& grid, int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

bool usedInRow(const vector<vector<int>>& grid, int row, int num) {
    for (int col = 0; col < SIZE; ++col) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInCol(const vector<vector<int>>& grid, int col, int num) {
    for (int row = 0; row < SIZE; ++row) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(const vector<vector<int>>& grid, int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

void printSudoku(const vector<vector<int>>& grid) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}
