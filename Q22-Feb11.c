/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
First line: two integers m and n representing the number of rows and columns
Next m lines: n integers each representing the elements of the first matrix
Next m lines: n integers each representing the elements of the second matrix

Output:
Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.*/
#include<stdio.h>
int main()
{
int arr[3][3];
printf("Input the values\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        scanf("%d", &arr[i][j]);
    }
}
printf("The matrix is\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        printf("%d\t", arr[i][j]);
}
printf("\n");
}
int a[3][3];
printf("Input the values\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        scanf("%d", &a[i][j]);
    }
}
printf("The matrix is\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        printf("%d\t", a[i][j]);
}
printf("\n");
}
int sum[3][3];
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        sum[i][j]=arr[i][j]+a[i][j];
    }
}
printf("The sum is-\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        printf("%d\t", sum[i][j]);
}
printf("\n");
}
    return 0;
}