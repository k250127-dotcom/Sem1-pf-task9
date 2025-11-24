#include <stdio.h>

void process2DArray(int arr[][4], int rows) {
    printf("Processing 2D array (arr1 type):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// array of pointers
void processPointerArray(int *arr[], int rows, int cols) {
    printf("Processing array of pointers (arr2 type):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// pointer to array
void processPointerToArray(int (*arr)[4], int rows) {
    printf("Processing pointer to array (arr3 type):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void demonstrateDeclarations() {
    printf("=== Array Declarations Demonstration ===\n\n");

    int arr1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int *arr2[3];
    int row0[4] = {13, 14, 15, 16};
    int row1[4] = {17, 18, 19, 20};
    int row2[4] = {21, 22, 23, 24};
    arr2[0] = row0;
    arr2[1] = row1;
    arr2[2] = row2;
    
    
    int (*arr3)[4] = arr1; 
    
    printf("Memory layout:\n");
    printf("arr1: Contiguous block of 12 integers\n");
    printf("arr2: Array of 3 pointers, each pointing to separate arrays\n");
    printf("arr3: Single pointer that can point to arrays of 4 integers\n\n");
    
    
    process2DArray(arr1, 3);
    printf("\n");
    
    processPointerArray(arr2, 3, 4);
    printf("\n");
    
    processPointerToArray(arr3, 3);
    printf("\n");
    
    // Demonstrate what happens with wrong types (commented out to avoid compilation errors)
    printf("If you try to pass wrong types:\n");
    printf("- process2DArray(arr2, 3); // COMPILER ERROR: incompatible pointer types\n");
    printf("- processPointerArray(arr1, 3, 4); // COMPILER ERROR: incompatible pointer types\n");
    printf("- processPointerToArray(arr2, 3); // COMPILER ERROR: incompatible pointer types\n");
    
    // Show memory addresses to illustrate differences
    printf("\nMemory addresses:\n");
    printf("arr1[0][0] at: %p, arr1[0][1] at: %p (difference: %ld bytes)\n", 
           &arr1[0][0], &arr1[0][1], (long)(&arr1[0][1] - &arr1[0][0]));
    printf("arr2[0] points to: %p, arr2[1] points to: %p\n", arr2[0], arr2[1]);
    printf("arr3 points to: %p\n", arr3);
}

int main() {
    demonstrateDeclarations();
    return 0;
}