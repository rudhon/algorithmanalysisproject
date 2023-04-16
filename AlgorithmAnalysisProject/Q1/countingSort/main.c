#include <stdio.h>
#include <stdlib.h>
void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void countingSort(int arr[], int n){
    int k = arr[0];
    int i, j;
    for(i = 1; i < n; i++){
        if (arr[i] > k) {
            k = arr[i];
        }
    }
    int C[k+1];
    int B[n];
    for(i = 0; i <= k; i++){
        C[i] = 0;
    }
    for(j = 0; j < n; j++){
        C[arr[j]] = C[arr[j]] + 1;
    }
    for(i = 1; i <= k; i++){
        C[i] = C[i] + C[i - 1];
    }
    for(j = n - 1; j >= 0; j--){
        B[C[arr[j]] - 1] = arr[j];
        C[arr[j]] = C[arr[j]] - 1;

    }

    for(i = 0; i < n; i++){
        arr[i] = B[i];
    }


}
int main()
{
    int arr[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array\n");
    printArr(arr, n);
    countingSort(arr, n);
    printf("Sorted Array\n");
    printArr(arr, n);
    return 0;
}
