#include <iostream>
#include <vector>
using namespace std;
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '.') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

void playGame() {
    vector<vector<char>> board(3, vector<char>(3, '.'));
    char currentPlayer = 'X';
    bool gameOngoing = true;

    while (gameOngoing) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != '.') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row-1][col-1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " won !!" << endl;
            gameOngoing = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "draw!" << endl;
            gameOngoing = false;
        } else {
            switchPlayer(currentPlayer);
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
