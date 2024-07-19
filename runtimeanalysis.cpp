// CSCI 411 - Spring 2023
// Run Time Analysis of Soduku Solver utilizing backtracking for 9x9 game boards and 16x16 game boards
// Author: Gio DiSalvo
#include <iostream>
#include <chrono>
using namespace std;
#include <vector>


// function to check if a move is valid
bool isValid(int board[9][9], int x, int y, int num) {
    // check row
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == num) {
            return false;
        }
    }
    // check column
    for (int j = 0; j < 9; j++) {
        if (board[j][y] == num) {
            return false;
        }
    }
    // check subgrid
    int row = x - (x % 3);
    int col = y - (y % 3);
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// function to find the coordinates of the next empty cell
pair<int, int> nextEmptyCell(int board[9][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (board[x][y] == 0) {
                return {x, y};
            }
        }
    }
    return {-1, -1};
}

// function to check if the board is completely filled
bool isBoardFilled(int board[9][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (board[x][y] == 0) {
                return false;
            }
        }
    }
    return true;
}

// function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int board[9][9]) {
    // if the board is completely filled, we are done
    if (isBoardFilled(board)) {
        return true;
    }
    // find the next empty cell
    pair<int, int> coords = nextEmptyCell(board);
    int x = coords.first;
    int y = coords.second;
    // try each number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // check if the move is valid
        if (isValid(board, x, y, num)) {
            // make the move
            board[x][y] = num;
            // try to solve the remaining board recursively
            if (solveSudoku(board)) {
                return true;
            }
            // undo the move and try the next number
            board[x][y] = 0;
        }
    }
    // if no move is valid, backtrack
    return false;
}

void printBoard(int board[][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


//same functions for 16x16
//
//
//

void print_board(int board[][16]) {
    for (int i = 0; i < 16; i++) {
        if (i % 4 == 0 && i != 0) {
            cout << "------------------------------------------" << endl;
        }
        for (int j = 0; j < 16; j++) {
            if (j % 4 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_valid(int board[16][16], int row, int col, int num) {
    // check row
    for (int i = 0; i < 16; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < 16; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // check subgrid
    int subgrid_row = row / 4 * 4;
    int subgrid_col = col / 4 * 4;
    for (int i = subgrid_row; i < subgrid_row + 4; i++) {
        for (int j = subgrid_col; j < subgrid_col + 4; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[16][16], int row, int col) {
    if (row == 16) {
        return true;
    }
    if (col == 16) {
        return solve_sudoku(board, row + 1, 0);
    }
    if (board[row][col] != 0) {
        return solve_sudoku(board, row, col + 1);
    }
    for (int num = 1; num <= 16; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}


int main() {
    // initialize the board
    int board[9][9] = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
};

// print the initial board
    cout << "Initial board:" << endl;
    printBoard(board);

    // solve the Sudoku puzzle and measure the time it takes
    auto start = chrono::high_resolution_clock::now();
    if (solveSudoku(board)) {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "Solved board:" << endl;
        printBoard(board);
        cout << "Time taken: " << duration << " microseconds" << endl;
    } else {
        cout << "unsolvable!" << endl;
    }


//for 16x16
//
//
//
int board2[16][16] = {
    {0, 15, 0, 1, 0, 2, 10, 14, 12, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 3, 16, 12, 0, 8, 4, 14, 15, 1, 0, 2, 0, 0, 0},
    {14, 0, 9, 7, 11, 3, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 13, 2, 12, 0, 0, 0, 0, 6, 0, 0, 0, 0, 15, 0, 0},
    {0, 0, 0, 0, 14, 1, 11, 7, 3, 5, 10, 0, 0, 8, 0, 12},
    {3, 16, 0, 0, 2, 4, 0, 0, 0, 14, 7, 13, 0, 0, 5, 15},
    {11, 0, 5, 0, 0, 0, 0, 0, 0, 9, 4, 0, 0, 6, 0, 0},
    {0, 0, 0, 0, 13, 0, 16, 5, 15, 0, 0, 12, 0, 0, 0, 0},
    {0, 0, 0, 0, 9, 0, 1, 12, 0, 8, 3, 10, 11, 0, 15, 0},
    {2, 12, 0, 11, 0, 0, 14, 3, 5, 4, 0, 0, 0, 0, 9, 0},
    {6, 3, 0, 4, 0, 0, 13, 0, 0, 11, 9, 1, 0, 12, 16, 2},
    {0, 0, 10, 9, 0, 0, 0, 0, 0, 0, 12, 0, 8, 0, 6, 7},
    {12, 8, 0, 0, 16, 0, 0, 10, 0, 13, 0, 0, 0, 5, 0, 0},
    {5, 0, 0, 0, 3, 0, 4, 6, 0, 1, 15, 0, 0, 0, 0, 0},
    {0, 9, 1, 6, 0, 14, 0, 11, 0, 0, 2, 0, 0, 0, 10, 8},
    {0, 14, 0, 0, 0, 13, 9, 0, 4, 12, 11, 8, 0, 0, 2, 0}
};

// TODO: populate the board with initial values

    cout << "Initial board:" << endl;
    print_board(board2);

    // solve the Sudoku puzzle and measure the time it takes
    auto start16 = chrono::high_resolution_clock::now();
    if (solve_sudoku(board2, 0, 0)) {
        auto end16 = chrono::high_resolution_clock::now();
        auto duration16 = chrono::duration_cast<chrono::microseconds>(end16 - start16).count();

        cout << "Solved board:" << endl;
        print_board(board2);
        cout << "Time taken: " << duration16 << " microseconds" << endl;
    } else {
        cout << "unsolvable!" << endl;
    }

return 0;

}