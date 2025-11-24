/*  Task 01 */

#include <stdio.h>

int mysteryAccess(int *ptr, int rows, int cols, int i, int j) {
    return *(ptr + i * cols + j);
}

void printSpiral(int *ptr, int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while(top <= bottom && left <= right) {
        for(int j = left; j <= right; j++)
            printf("%d ", *(ptr + top * cols + j));
        top++;

        for(int i = top; i <= bottom; i++)
            printf("%d ", *(ptr + i * cols + right));
        right--;

        if(top <= bottom) {
            for(int j = right; j >= left; j--)
                printf("%d ", *(ptr + bottom * cols + j));
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                printf("%d ", *(ptr + i * cols + left));
            left++;
        }
    }
    printf("\n");
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter elements of the array:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);

    int r, c;
    printf("Enter row and column to access (0-indexed): ");
    scanf("%d %d", &r, &c);
    printf("Element at (%d,%d): %d\n", r, c, mysteryAccess(&arr[0][0], rows, cols, r, c));

    printf("Spiral order:\n");
    printSpiral(&arr[0][0], rows, cols);

    return 0;
}