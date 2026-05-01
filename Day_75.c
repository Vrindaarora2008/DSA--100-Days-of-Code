/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
Input Format
An integer array arr[].
Output Format
Print the length of the longest subarray with sum equal to zero.
Sample Input
15 -2 2 -8 1 7 10 23
Sample Output
5
Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray*/
#include<stdio.h>
#include<stdlib.h>
int longestZeroSumSubarray(int arr[], int n) 
{
    int *hashMap = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        hashMap[i] = -1;
    }
    int maxLength = 0;
    int cumulativeSum = 0;
    for (int i = 0; i < n; i++) 
    {
        cumulativeSum += arr[i];
        if (cumulativeSum == 0) 
        {
            maxLength = i + 1; 
        }
        else if (hashMap[cumulativeSum] != -1) 
        {
            int length = i - hashMap[cumulativeSum];
            if (length > maxLength) 
            {
                maxLength = length;
            }
        } 
        else 
        {
            hashMap[cumulativeSum] = i; 
        }
    }
    free(hashMap); 
    return maxLength;
}
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);
    return 0;
}
