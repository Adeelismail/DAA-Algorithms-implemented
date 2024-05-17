#include <stdio.h>

void countSort(int arr[], int n, int pos) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int pos = 1; max / pos > 0; pos *= 10)
        countSort(arr, n, pos);
}

int main() {
    int array[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    int n = sizeof(array) / sizeof(array[0]);

    radixSort(array, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
