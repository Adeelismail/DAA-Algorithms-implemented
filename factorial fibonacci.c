#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

int fibonacci(int n) {
    if (n < 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Fibonacci of %d is %d\n", n, fibonacci(n));
    return 0;
}
