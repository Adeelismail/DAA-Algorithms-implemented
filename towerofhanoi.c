#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from Source %c to Target %c\n", source, target);
        return;
    } else {
        towerOfHanoi(n - 1, source, target, auxiliary);
        printf("Move disk %d from Source %c to Auxiliary %c\n", n, source, auxiliary);
        towerOfHanoi(n - 1, auxiliary, source, target);
    }
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
