/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
Books must be allocated in contiguous order.
Input Format
n m
n space-separated integers representing pages in books
Output Format
Print the minimum possible value of the maximum pages assigned to any student.
Sample Input
4 2
12 34 67 90
Sample Output
113
Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/
#include<stdio.h>
#include<stdlib.h>
int isPossible(int arr[], int n, int m, int mid) 
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > mid) 
        {
            return 0; 
        }
        if (pageSum + arr[i] > mid) 
        {
            studentCount++;
            pageSum = arr[i]; 
            if (studentCount > m) 
            {
                return 0; 
            }
        } 
        else 
        {
            pageSum += arr[i]; 
        }
    }
    return 1; 
}