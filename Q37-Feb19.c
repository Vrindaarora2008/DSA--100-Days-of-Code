/*Problem: Given an array of integers, find two elements whose sum is closest to zero.
Input:
First line: integer n
Second line: n space-separated integers
Output:
Print the pair of elements whose sum is closest to zero
Example:
Input:
5
1 60 -10 70 -80
Output:
-10 1
Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include<stdio.h>
#include<math.h>
int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);    
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int min_sum = __INT_MAX__; 
    int pair1, pair2;
    for(int i = 0; i < n; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {
            int sum = arr[i] + arr[j];
            if(abs(sum) < abs(min_sum)) 
            {
                min_sum = sum;
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }
    printf("The pair of elements whose sum is closest to zero is: %d %d\n", pair1, pair2);
    return 0;
}