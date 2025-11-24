#include <stdio.h>

typedef void* (*StateFunc)(int*);

// Define functions in reverse order to avoid needing prototypes
void* stateD(int *data) {
    printf("State D: Final result = %d\n", *data);
    printf("Game completed!\n");
    return NULL;
}

void* stateC(int *data) {
    printf("State C: Adding 10 to %d\n", *data);
    *data = *data + 10;
    printf("Result: %d, going to State D\n", *data);
    return stateD;
}

void* stateB(int *data) {
    printf("State B: Multiplying %d by 2\n", *data);
    *data = *data * 2;
    printf("Result: %d, going to State D\n", *data);
    return stateD;
}

void* stateA(int *data) {
    printf("State A: Enter a number: ");
    scanf("%d", data);
    
    if (*data > 5) {
        printf("Number > 5, going to State B\n");
        return stateB;
    } else {
        printf("Number <= 5, going to State C\n");
        return stateC;
    }
}

int main() {
    printf("=== Pointer State Machine Game ===\n");
    printf("Rules:\n");
    printf("- Enter number > 5: goes to State B (multiply by 2)\n");
    printf("- Enter number <= 5: goes to State C (add 10)\n");
    printf("- Both paths end at State D (display result)\n\n");
    
    int data = 0;
    StateFunc currentState = stateA;
    
    while (currentState != NULL) {
        currentState = (StateFunc)currentState(&data);
    }
    
    return 0;
}