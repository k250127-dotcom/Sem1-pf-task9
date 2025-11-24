#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}

void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByPointer: *a = %d, *b = %d\n", *a, *b);
}

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference: *a = %d, *b = %d\n", *a, *b);
}

// 2D array
void swapRows(int **arr, int row1, int row2, int cols) {
    int *temp = arr[row1];
    arr[row1] = arr[row2];
    arr[row2] = temp;
}

void swapRowsStatic(int arr[][3], int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
    }
}

void demonstrateSwaps() {
    int x = 5, y = 10;
    printf("Before any swap: x = %d, y = %d\n", x, y);
    
    // won't change x and y in main
    swapByValue(x, y);
    printf("After swapByValue: x = %d, y = %d\n\n", x, y);
    
    
    x = 5; y = 10;
    
    // change x and y
    swapByPointer(&x, &y);
    printf("After swapByPointer: x = %d, y = %d\n\n", x, y);
    

    x = 15; y = 25;
    
    // swapByReference - will change x and y (same as pointer version)
    swapByReference(&x, &y);
    printf("After swapByReference: x = %d, y = %d\n\n", x, y);
}

void demonstrateRowSwap() {
    printf("\n--- 2D Array Row Swap ---\n");
    
    // Dynamic 2D array 
    int rows = 3, cols = 3;
    int *arr2D[3];
    

    for (int i = 0; i < rows; i++) {
        arr2D[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr2D[i][j] = i * cols + j + 1;
        }
    }
    
    printf("Before row swap:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
    
    swapRows(arr2D, 0, 2, cols);
    
    printf("\nAfter swapping row 0 and row 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(arr2D[i]);
    }
}

int main() {
    demonstrateSwaps();
    demonstrateRowSwap();
    return 0;
}