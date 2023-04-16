#include <stdio.h>
#include <stdlib.h>

int partitionLast(int arr[], int p, int q) {
    int x = arr[q];
    int i = p - 1;

    for(int j = p; j <= q - 1; j++) {
        if(arr[j] <= x) {

            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;


        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[q];
    arr[q] = temp;

    return i + 1;
}

void quickSortLast(int arr[], int p, int r) {
    if(p < r) {

        int q = partitionLast(arr, p, r);

        quickSortLast(arr, p, q - 1);
        quickSortLast(arr, q + 1, r);


    }
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 8, 6, 9, 4, 3, 1, 5, 2, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortLast(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}
