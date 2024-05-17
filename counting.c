#include <stdio.h>

void countingSort(int arr[], int n) {
    int k = 0;
        for (int i = 0; i < n; i++) {
        if (arr[i] > k)
            k = arr[i];
    }
    
    int count[k + 1];
    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

       for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    int sorted_arr[n];
    for (int i = n - 1; i >= 0; i--) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }
}

int main() {
    int a[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    int n = sizeof(a) / sizeof(a[0]);
    countingSort(a, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
