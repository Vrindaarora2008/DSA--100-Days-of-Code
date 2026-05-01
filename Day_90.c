/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
Determine the minimum time required to paint all boards.
Input Format
n k
n space-separated integers representing board lengths
Output Format
Print the minimum time required to paint all boards.
Sample Input
4 2
10 20 30 40
Sample Output
60
Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include<stdio.h>
#include<stdlib.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int isPossible(int boards[], int n, int k, int mid) 
{
    int painters = 1;
    int time = 0;
    for (int i = 0; i < n; i++) 
    {
        if (time + boards[i] <= mid) 
        {
            time += boards[i];
        } 
        else 
        {
            painters++;
            time = boards[i];
            if (painters > k) 
            {
                return 0;
            }
        }
    }
    return 1; 
}
int minTime(int boards[], int n, int k) 
{
    int low = 0;
    int high = 0;
    for (int i = 0; i < n; i++) 
    {
        high += boards[i];
        low = max(low, boards[i]);
    }
    while (low < high) 
    {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) 
        {
            high = mid; // Try for a smaller time
        } 
        else 
        {
            low = mid + 1; // Increase time
        }
    }
    return low;
}
int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *boards = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &boards[i]);
    }
    int result = minTime(boards, n, k);
    printf("%d\n", result);
    free(boards);
    return 0;
}
