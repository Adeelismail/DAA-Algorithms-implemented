#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, current;
    for (i = 1; i < n; i++) {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main() {
    int a[] = {60, 20, 76, 98, 29, 10};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
