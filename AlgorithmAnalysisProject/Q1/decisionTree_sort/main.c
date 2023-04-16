#include <stdio.h>
#include <stdlib.h>
//to do
//learn the difference between insertion sort and decision tree sort
//Stability
//Insertion Sort: It is a stable sorting algorithm, which means it maintains the relative order of equal elements in the sorted array.
//Decision Tree Sort: It is not inherently stable since it only compares elements based on their values, without considering their order of appearance in the original array.
// most important difference is time complexity


void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void decision_tree_sort(int array[], int length) {
    int i, j, temp;
    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                printArr(array, length);
            }
        }
    }
}

int main() {
    int array[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int length = sizeof(array)/sizeof(array[0]);
    printf("Unsorted Array\n");
    printArr(array, length);
    decision_tree_sort(array, length);
    int i;
    printf("Sorted Array\n");
    printArr(array, length);
    return 0;
}
