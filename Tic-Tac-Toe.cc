#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void drawBoard() {
    cout << "  Tic-Tac-Toe" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " | " << board[i][j];
        }
        cout << " | " << endl << "--------------" << endl;
    }
}

bool isMoveValid(int choice) {
    if (choice < 1 , choice > 9) {
        cout << "Invalid move! Choose a number between 1 and 9." << endl;
        return false;
    }
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] == 'X' , board[row][col] == 'O') {
        cout << "Cell already occupied! Choose another cell." << endl;
        return false;
    }
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int choice;
    bool gameOver = false;
    while (!gameOver) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;
        if (isMoveValid(choice)) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            board[row][col] = currentPlayer;
            if (checkWin()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }
    }
    return 0;
}
