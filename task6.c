#include <stdio.h>
#include <string.h>


int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { 
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b; 
}

int (*getCommand(char *command))(int, int) {
    if (strcmp(command, "add") == 0) return add;
    if (strcmp(command, "sub") == 0) return subtract;
    if (strcmp(command, "mul") == 0) return multiply;
    if (strcmp(command, "div") == 0) return divide;
    return NULL; 
}

int main() {
    printf("=== Function Router ===\n");
    
    int a = 20, b = 5;
    char *commands[] = {"add", "sub", "mul", "div", "invalid"};
    
    for (int i = 0; i < 5; i++) {
        printf("Command: %s\n", commands[i]);
        
        int (*operation)(int, int) = getCommand(commands[i]);
        
        if (operation != NULL) {
            int result = operation(a, b);
            printf("Result: %d %s %d = %d\n\n", a, commands[i], b, result);
        } else {
            printf("Error: Invalid command '%s'!\n\n", commands[i]);
        }
    }
    
    return 0;
}
