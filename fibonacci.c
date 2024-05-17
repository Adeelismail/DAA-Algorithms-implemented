#include <stdio.h>

int fibDP(int n) {
    int a = 0, b = 1, c;
    
    if (n < 0)
        return -1;
    else if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else {
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main() {
    printf("%d\n", fibDP(10));
    return 0;
}
