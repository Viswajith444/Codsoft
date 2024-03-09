// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the game board
vector<vector<char>> initializeBoard() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    return board;
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1   2   3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "  ---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the board is full
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = initializeBoard();
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (true) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! The game is over." << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        printf("\x1b[2J");
        printf("\x1b[H");
    }

    return 0;
}
