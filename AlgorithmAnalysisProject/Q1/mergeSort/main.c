#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("%s", "\n");
}
// ilk parca sol dan orta ya
// ikinci parca orta dan sag a
void mergeSort(int arr[], int sol, int sag){
    if(sol < sag){
        int orta = sol+(sag-sol)/2;
        mergeSort(arr, sol, orta);
        mergeSort(arr, orta + 1, sag);

        merge(arr, sol, orta, sag);
    }
    return;
}
//
void merge(int arr[], int sol, int orta, int sag){
    int i = 0, j = 0, k;
    int len1 = orta - sol + 1;
    int len2 = sag - orta;
    int arrRight[len2];
    int arrLeft[len1];
    for(i; i < len1; i++){
        arrLeft[i] = arr[sol + i];
    }
    for(j; j < len2; j++){
        arrRight[j] = arr[orta + 1 + j];
    }
    i = 0;
    j = 0;
    k = sol;
   while (i < len1 && j < len2)
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++;
        }
        else
        {
            arr[k] = arrRight[j];
            j++;
        }
        k++;

    }
    while (i < len1)
    {
        arr[k] = arrLeft[i];
        i++;
        k++;

    }

    while (j < len2)
    {
        arr[k] = arrRight[j];
        j++;
        k++;

    }


}



int main()
{
    int arr[] = { 8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array\n");
    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array in ascending order:\n");
    printArr(arr, n);
    return 0;
}
