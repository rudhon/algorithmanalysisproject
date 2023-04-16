#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* TO DO
    RASTGELE URETILEN SAYILAR TEXT DOSYASINDAN OKUNACAK
    OUTPUT TEXT DOSYASINA YAZILACAK
*/
#define SIZE 15000

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
void decision_tree_sort(int array[], int length) {
    int i, j, temp;
    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

            }
        }
    }
}
void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;

   }
}
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
int partitionFirst(int arr[], int p, int q){
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
void quickSortFirst(int arr[], int p, int r){
    int q;
    if(p < r){
        q = partitionFirst(arr, p, r);
        quickSortFirst(arr, p, q - 1);
        quickSortFirst(arr, q, r);

    }


}
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
void copyArr(int arr[], int temp[], int n){
    int i;
    for(i = 0; i < n; i++){
        temp[i] = arr[i];
    }

}
int main() {
    clock_t start, end;
    double time;

    FILE *fp = NULL, *fout = NULL;
    int arr[SIZE];
    int i = 0;

    fp = fopen("numbers15.txt", "r");

    if (fp == NULL) {
        printf("Dosya açılamadı.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &arr[i]) == 1 && i < SIZE) {
        i++;
    }
    fclose(fp);
    int temp[SIZE];
    copyArr(arr, temp, SIZE);

    // Dosyaya yazma işlemi
    fout = fopen("A15.txt", "w");
    if(fout == NULL) {
        printf("Dosya acilamadi.\n");
        return 0;
    }
    // Quick Sort Pivot First
    start = clock();
    quickSortFirst(temp, 0, SIZE-1);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Quick Sort Pivot First: %.10f\n", time);

    copyArr(arr, temp, SIZE);

    // Quick Sort Pivot Last
    start = clock();
    quickSortLast(temp, 0, SIZE - 1);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Quick Sort Pivot Last: %.10f\n", time);

    copyArr(arr, temp, SIZE);

    // Insertion Sort
    start = clock();
    insertionSort(temp, SIZE);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Insertion Sort: %.10f\n", time);

    copyArr(arr, temp, SIZE);

    // Merge Sort
    start = clock();
    mergeSort(temp, 0, SIZE-1);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Merge Sort: %.10f\n", time);

    copyArr(arr, temp, SIZE);

    // Counting Sort
    start = clock();
    countingSort(temp, SIZE);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Counting Sort: %.10f\n", time);

    copyArr(arr, temp, SIZE);


    // Decision Tree Sort
    start = clock();
    decision_tree_sort(temp, SIZE);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(fout, "Decision Tree Sort: %.10f\n", time);

    fclose(fout);





    return 0;

}
