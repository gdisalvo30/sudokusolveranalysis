// CSCI 411 - Spring 2023
// The implementation of the Sudoku Solver utilizing backtracking
// Author: Gio DiSalvo
#include <iostream>
using namespace std;

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

void printBoard(int board[9][9]) {
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

int main() {
    int board[9][9];
    // get input for the board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << "----------------------------------------" << endl;
    cout << "Input Board:" << endl;
    cout << "----------------------------------------" << endl;
    printBoard(board);
    
    // solve the puzzle
    if (solveSudoku(board)) {
        cout << "----------------------------------------" << endl;
        cout << "Puzzle was solved!" << endl;
        cout << "----------------------------------------" << endl;
        printBoard(board);
    } else {
        cout << "Unable to solve the puzzle." << endl;
    }
    return 0;
}