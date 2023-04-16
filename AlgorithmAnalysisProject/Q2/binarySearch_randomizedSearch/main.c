#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// TO DO
//  PARTITION KISMINA TEKRAR BAK
//  QUICK SORT PARTITION KARSILASTIR
//BINARY SEARCH
int find_tth_min(int arr[], int n, int t)
{
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        int count = 0, count_equal = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < mid) {
                count++;
            } else if (arr[i] == mid) {
                count_equal++;
            }
        }

        if (count < t && count + count_equal >= t) {
            return mid;
        }
        else if (count >= t) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}
//BINARY SEARCH
//RANDOMIZED SEARCH
int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    int temp = arr[right];
    arr[right] = arr[pivotIndex];
    arr[pivotIndex] = temp;
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            temp = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = temp;
            storeIndex++;
        }
    }
    temp = arr[storeIndex];
    arr[storeIndex] = arr[right];
    arr[right] = temp;
    return storeIndex;
}
// RASTGELE PIVOT SECIMI
int randomizedPartition(int arr[], int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    return partition(arr, left, right, pivotIndex);
}

int findKthSmallest(int arr[], int left, int right, int k) {
    while (1) {
        if (left == right) {
            return arr[left];
        }
        int pivotIndex = randomizedPartition(arr, left, right);
        int pivotDist = pivotIndex - left + 1;
        if (k == pivotDist) {
            return arr[pivotIndex];
        } else if (k < pivotDist) {
            right = pivotIndex - 1;
        } else {
            k -= pivotDist;
            left = pivotIndex + 1;
        }
    }
}

int main()
{
    int A[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int arr[] = {8, 6, 9, 4, 3, 1, 5, 2, 7};
    int n = sizeof(A) / sizeof(A[0]);
    //Target
    int t = 5;
    int k = 5;
    //Target
    int tth_min = find_tth_min(A, n, t);
    printf("%dth smallest element is %d\n", t, tth_min);
    srand(time(NULL)); // random seed
    int kthSmallest = findKthSmallest(arr, 0, n - 1, k);
    printf("%dth smallest element is %d\n", k, kthSmallest);

    return 0;
}
