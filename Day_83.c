/*Problem: Implement Selection Sort - Implement the algorithm.
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
void selectionSort(int arr[], int n) 
{
    int min_idx;
    for (int i = 0; i < n-1; i++) 
    {
        min_idx = i;
        for (int j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main() 
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}