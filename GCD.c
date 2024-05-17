#include <stdio.h>

int euclid(int x, int y) {
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if (y == 0)
        return x;
    else
        return euclid(y, x % y);
}

int main() {
    int x = 48, y = 18;
    printf("GCD of %d and %d is %d\n", x, y, euclid(x, y));
    return 0;
}
