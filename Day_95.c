/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void bucket_sort(float arr[], int n) 
{
    float buckets[MAX][MAX];
    int bucket_count[MAX] = {0};
    for (int i = 0; i < n; i++) 
    {
        int index = (int)(arr[i] * MAX); 
        buckets[index][bucket_count[index]++] = arr[i];
    }
    for (int i = 0; i < MAX; i++) 
    {
        if (bucket_count[i] > 0) 
        {
            for (int j = 1; j < bucket_count[i]; j++) 
            {
                float key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) 
                {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < MAX; i++) 
    {
        for (int j = 0; j < bucket_count[i]; j++) 
        {
            arr[index++] = buckets[i][j];
        }
    }
}
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    return 0;
}
