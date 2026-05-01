/*Problem: Implement Insertion Sort - Implement the algorithm.
Input:
First line: integer n
Second line: n space-separated integers
Output:
Print the sorted array or search result
Example:
Input:
5
64 34 25 12 22
Output:
12 22 25 34 64*/
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() 
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }  
    insertionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
