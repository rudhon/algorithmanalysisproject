#include <stdio.h>
#include <stdlib.h>

int partitioN(int arr[], int p, int q){
    int x = arr[p];
    int i = p;
    int j = p + 1;
    int temp;
    for( j ; j < q; j++){
        if(arr[j] <= x){
            ++i;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
    }
    arr[p] = arr[i];
    arr[i] = x;
    return (i + 1);
}
void quickSort(int arr[], int p, int r){
    int q;
    if(p < r){
        q = partitioN(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q, r);

    }


}
void printArr(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("%s", "\n");
}

int main()
{
    int arr[] = { 8, 6, 9, 4, 3, 1, 5, 2, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n);
    printArr(arr, n);

    return 0;
}
