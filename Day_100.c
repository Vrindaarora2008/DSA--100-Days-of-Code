/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int countSmaller(int arr[], int n) {
    int count[MAX] = {0}; // Array to store the count of smaller elements
    int temp[MAX]; // Temporary array for merge sort

    // Function to perform merge sort and count smaller elements
    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        // Merge step
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count[arr[i]] += (mid - i + 1); // Count smaller elements
            }
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
    }

    mergeSort(0, n - 1);

    // Print the count of smaller elements for each element
    for (int i = 0; i < n; i++) {
        printf("%d ", count[arr[i]]);
    }
}
int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Count of smaller elements to the right: ");
    countSmaller(arr, n);
    return 0;
}
