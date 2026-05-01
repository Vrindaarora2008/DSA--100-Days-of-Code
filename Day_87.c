/*Problem: Implement Binary Search Iterative - Implement the algorithm.
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
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array\n");
    printArray(arr, n);
    free(arr);
    return 0;
}
