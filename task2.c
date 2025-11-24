#include <stdio.h>
#include <stdlib.h>

// Basic arithmetic operations
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero!\n");
        return a;
    }
    return a / b;
}

int chainCalc(int start, int *values, int n, int (**ops)(int, int))
{
    int result = start;

    for (int i = 0; i < n; i++)
    {
        result = ops[i](result, values[i]);
        printf("Step %d: result = %d\n", i + 1, result);
    }

    return result;
}

int main()
{
    // Create array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int values[] = {5, 3, 4, 2};
    int n = sizeof(values) / sizeof(values[0]);

    // Test different operation sequences
    int (*ops1[4])(int, int) = {operations[0], operations[1], operations[2], operations[3]};
    printf("Calculation 1: 10 + 5 - 3 * 4 / 2\n");
    int result1 = chainCalc(10, values, n, ops1);
    printf("Final result: %d\n\n", result1);

    int (*ops2[4])(int, int) = {operations[2], operations[0], operations[3], operations[1]};
    printf("Calculation 2: 10 * 5 + 3 / 4 - 2\n");
    int result2 = chainCalc(10, values, n, ops2);
    printf("Final result: %d\n", result2);

    return 0;
}