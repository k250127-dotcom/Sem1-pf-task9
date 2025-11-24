#include <stdio.h>
#include <stdlib.h>

// Comparison functions
int ascending(int a, int b) { return a > b; }  
int descending(int a, int b) { return a < b; } 
int absolute(int a, int b) { return abs(a) > abs(b); } 

// Sort using function pointer
void customSort(int *arr, int size, int (*condition)(int, int)) {
    // Simple bubble sort
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (condition(arr[j], arr[j+1])) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Print array
void printArray(int *arr, int size, char *title) {
    printf("%s: ", title);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("=== Callback Sorting ===\n");
    
    int arr[] = {-5, 3, -1, 8, -2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    

    int arr1[6], arr2[6], arr3[6];
    
    // original array
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr[i];
    }
    
    printf("Original array: ");
    printArray(arr, size, "");
    printf("\n");
    
    // ascending order
    customSort(arr1, size, ascending);
    printArray(arr1, size, "Ascending order");
    
    // descending order
    customSort(arr2, size, descending);
    printArray(arr2, size, "Descending order");
    
    // absolute value
    customSort(arr3, size, absolute);
    printArray(arr3, size, "Absolute value order");
    
    return 0;
}