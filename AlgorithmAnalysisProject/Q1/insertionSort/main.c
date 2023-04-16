#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n);
void insertionSort(int arr[], int n);


int main() {
   int arr[] = { 8, 6, 9, 4, 3, 1, 5, 2, 7 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int i;
   int tempArr[n];


   printf("Unsorted Array\n");
   printArr(arr, n);

   insertionSort(arr, n);

   printf("\nSorted Array\n");
   printArr(arr, n);

   return 0;
}

void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
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
       printArr(arr, n);
   }
}













































