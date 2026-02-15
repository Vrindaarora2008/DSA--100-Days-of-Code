/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
Input:
First line: two integers m and n
Next m lines: n integers each
Output:
Print the sum of the primary diagonal elements
Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output:
15
Explanation:
1 + 5 + 9 = 15*/
#include <stdio.h>
int main()
{
int arr[3][3];
int sum=0;
printf("Input the values\n");
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        scanf("%d", &arr[i][j]);
        if(i == j)
        {
            sum=sum+arr[i][j];
        }
    }
    printf("\n");
}
printf("Sum 1 is-%d\n", sum);
    return 0;
}//main diagnol elements