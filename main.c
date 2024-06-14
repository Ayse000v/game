#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 15
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

// 初始化棋盘
void initBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// 打印棋盘
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

// 检查是否有玩家获胜
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    char player = board[row][col];
    int count;

    // 检查行
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == player) count++;
        else count = 0;
        if (count == 5) return 1;
    }

    // 检查列
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == player) count++;
        else count = 0;
        if (count == 5) return 1;
    }

    // 检查对角线
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == player) count++;
        else count = 0;
        if (count == 5) return 1;
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (row + i < BOARD_SIZE && col + i < BOARD_SIZE && board[row + i][col + i] == player) count++;
        else count = 0;
        if (count == 5) return 1;
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col, player = 0;

    initBoard(board);
    printBoard(board);

    while (1) {
        printf("Player %d, enter row and column (1-%d): ", player % 2 + 1, BOARD_SIZE);
        scanf("%d %d", &row, &col);
        row--; col--; // 调整为数组索引

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (player % 2 == 0) ? PLAYER1 : PLAYER2;
        printBoard(board);

        if (checkWin(board, row, col)) {
            printf("Player %d wins!\n", player % 2 + 1);
            break;
        }

        player++;
    }

    return 0;
}
