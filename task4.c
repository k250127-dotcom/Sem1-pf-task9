#include <stdio.h>
#include <string.h>

// Compare functions for different data types
int compareInt(void *a, void *b) {
    int *num1 = (int*)a;
    int *num2 = (int*)b;
    return (*num1 > *num2) ? 1 : (*num1 < *num2) ? -1 : 0;
}

int compareFloat(void *a, void *b) {
    float *num1 = (float*)a;
    float *num2 = (float*)b;
    return (*num1 > *num2) ? 1 : (*num1 < *num2) ? -1 : 0;
}

int compareChar(void *a, void *b) {
    char *ch1 = (char*)a;
    char *ch2 = (char*)b;
    return (*ch1 > *ch2) ? 1 : (*ch1 < *ch2) ? -1 : 0;
}

// Generic maximum finder
void* findMax(void *arr, int size, int elementSize, int (*compare)(void*, void*)) {
    if (size <= 0) return NULL;
    
    void *max = arr; // Point to first element
    
    for (int i = 1; i < size; i++) {
        void *current = (char*)arr + i * elementSize;
        if (compare(current, max) > 0) {
            max = current;
        }
    }
    
    return max;
}

void testGenericMax() {
    printf("=== Testing Generic Maximum Finder ===\n");
    
    // Test with integers
    int intArr[] = {45, 23, 78, 12, 90, 34};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int *intMax = (int*)findMax(intArr, intSize, sizeof(int), compareInt);
    printf("Integer array: ");
    for (int i = 0; i < intSize; i++) printf("%d ", intArr[i]);
    printf("\nMaximum integer: %d\n\n", *intMax);
    
    // Test with floats
    float floatArr[] = {3.14f, 2.71f, 1.41f, 4.67f, 0.99f};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    float *floatMax = (float*)findMax(floatArr, floatSize, sizeof(float), compareFloat);
    printf("Float array: ");
    for (int i = 0; i < floatSize; i++) printf("%.2f ", floatArr[i]);
    printf("\nMaximum float: %.2f\n\n", *floatMax);
    
    // Test with characters
    char charArr[] = {'z', 'a', 'm', 'p', 'k'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    char *charMax = (char*)findMax(charArr, charSize, sizeof(char), compareChar);
    printf("Char array: ");
    for (int i = 0; i < charSize; i++) printf("%c ", charArr[i]);
    printf("\nMaximum char: %c\n", *charMax);
}

int main() {
    testGenericMax();
    return 0;
}