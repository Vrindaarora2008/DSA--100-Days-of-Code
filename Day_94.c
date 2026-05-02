/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include<stdio.h>
#include<stdlib.h>
void countingSort(int arr[], int n) 
{
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    int *freq = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        freq[arr[i]]++;
    }
    int *output = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i <= max; i++) 
    {
        while (freq[i] > 0) 
        {
            output[index++] = i;
            freq[i]--;
        }
    }
    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
    free(freq);
    free(output);
}
int main() 
 {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
