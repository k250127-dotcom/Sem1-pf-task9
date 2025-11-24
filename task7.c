#include <stdio.h>
#include <stdlib.h>

// making n x n matrix
int** createMatrix(int n) {
    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j + 1; 
        }
    }
    return matrix;
}


void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free matrix memory
void freeMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Rotate matrix 90 degrees clockwise
void rotateMatrix90(int **matrix, int n) {

    int **temp = createMatrix(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = temp[n-1-j][i];
        }
    }
    
    freeMatrix(temp, n);
}

int main() {
    printf("=== 2D Pointer Rotation ===\n");
    
    int n = 3;
    int **matrix = createMatrix(n);
    
    printf("Original 3x3 matrix:\n");
    printMatrix(matrix, n);
    
    rotateMatrix90(matrix, n);
    printf("\nAfter 90° clockwise rotation:\n");
    printMatrix(matrix, n);
    
    freeMatrix(matrix, n);
    return 0;
}