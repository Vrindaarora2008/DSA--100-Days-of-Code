/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
Input:
First line: two integers m and n representing the number of rows and columns
Next m lines: n integers each representing the elements of the matrix
Output:
Print "Symmetric Matrix" if the given matrix is symmetric
Otherwise, print "Not a Symmetric Matrix"
Example:
Input:
3 3
1 2 3
2 4 5
3 5 6
Output:
Symmetric Matrix
Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].*/
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter the number of rows\n");
    scanf("%d", &a);
    printf("Enter the number of columns\n");
    scanf("%d", &b);
    int arr[a][b], transpose[a][b];
    printf("Input the values:\n");
    for (int i=0;i<a;i++) 
    {
        for (int j=0;j<b;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The matrix is:\n");
    for (int i=0;i<a;i++) 
    {
        for (int j=0;j<b;j++) 
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
     for (int i=0;i<a;i++) 
    {
        for (int j=0;j<b;j++) 
        {
            transpose[i][j]=arr[j][i];
        }
        printf("\n");
    }
     for (int i=0;i<a;i++) 
    {
        for (int j=0;j<b;j++) 
        {
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(arr[i][j]==transpose[i][j])
            {
                printf("SYMMETRIC");
            }
        }
    }
    return 0;
}