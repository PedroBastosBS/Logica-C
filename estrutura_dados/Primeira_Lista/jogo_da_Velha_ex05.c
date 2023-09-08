#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true;
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;
    bool gameover = false;

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (!gameover) {
        printf("Jogador %c, insira as coordenadas (linha e coluna): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Coordenadas inválidas. Tente novamente.\n");
        } else {
            board[row][col] = currentPlayer;
            printBoard();

            if (checkWin(currentPlayer)) {
                printf("Jogador %c venceu!\n", currentPlayer);
                gameover = true;
            } else if (isDraw()) {
                printf("Empate!\n");
                gameover = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}

