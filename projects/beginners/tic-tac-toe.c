#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard();
void printBoard();
int checkWin();
int isBoardFull();
void makeMove();

int main() {
    initializeBoard();

    while (1) {
        printBoard();
        makeMove();

        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull()) {
            printBoard();
            printf("The game is a draw!\n");
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void makeMove() {
    int row, col;

    while (1) {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = currentPlayer;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}
