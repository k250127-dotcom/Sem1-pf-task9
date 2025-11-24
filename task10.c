#include <stdio.h>
#include <stdlib.h>

// Sample
int sampleFunction(int x) {
    return x * 2;
}

void printMemory(void *ptr, int size) {
    printf("Memory content (%d bytes): ", size);
    unsigned char *bytes = (unsigned char*)ptr;
    
    for (int i = 0; i < size; i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

int main() {
    printf("=== Memory Layout Detective ===\n\n");
    
    // Different variables
    int integer = 0x12345678;
    int *intPointer = &integer;
    int array[3] = {0xAABB, 0xCCDD, 0xEEFF};
    int (*arrayPointer)[3] = &array;
    int (*funcPointer)(int) = sampleFunction;
    
    // addresses and sizes
    printf("Variable         Address          Size\n");
    printf("--------------------------------------\n");
    printf("integer          %p  %zu bytes\n", (void*)&integer, sizeof(integer));
    printf("intPointer       %p  %zu bytes\n", (void*)&intPointer, sizeof(intPointer));
    printf("array            %p  %zu bytes\n", (void*)&array, sizeof(array));
    printf("arrayPointer     %p  %zu bytes\n", (void*)&arrayPointer, sizeof(arrayPointer));
    printf("funcPointer      %p  %zu bytes\n", (void*)&funcPointer, sizeof(funcPointer));
    
    printf("\n=== Memory Content Analysis ===\n\n");
    
    // Examine memory content of each variable
    printf("Integer (0x12345678):\n");
    printMemory(&integer, sizeof(integer));
    
    printf("\nInteger pointer (points to %p):\n", (void*)intPointer);
    printMemory(&intPointer, sizeof(intPointer));
    
    printf("\nArray [0xAABB, 0xCCDD, 0xEEFF]:\n");
    printMemory(array, sizeof(array));
    
    printf("\nFunction pointer:\n");
    printMemory(&funcPointer, sizeof(funcPointer));
    
    printf("\n=== Observations ===\n");
    printf("1. Pointers (intPointer, arrayPointer, funcPointer) have same size\n");
    printf("2. Integer 0x12345678 shows byte order (78 56 34 12) - little endian\n");
    printf("3. Array elements are stored contiguously in memory\n");
    printf("4. Addresses show memory alignment patterns\n");
    printf("5. Function pointer stores address of the function code\n");
    
    return 0;
}