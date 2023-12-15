#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printSolution(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int **board, int row, int col, int N) {
    int i, j;

    
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int **board, int col, int N) {
    if (col >= N) {
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            res = solveNQueensUtil(board, col + 1, N) || res;

            board[i][col] = 0; 
        }
    }

    return res;
}

void solveNQueens(int N) {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    if (!solveNQueensUtil(board, 0, N)) {
        printf("Solution does not exist");
    }

    
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    int N;

    printf("Enter the value of N for N-Queens: ");
    scanf("%d", &N);

    solveNQueens(N);

    return 0;
}
