/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    return ((int*)a)[0] - ((int*)b)[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) 
{
    if (intervalsSize == 0) 
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int **merged = (int**)malloc(intervalsSize * sizeof(int*));
    int mergedCount = 0;
    for (int i = 0; i < intervalsSize; i++) 
    {
        if (mergedCount == 0 || merged[mergedCount - 1][1] < intervals[i][0]) 
        {
            merged[mergedCount] = (int*)malloc(2 * sizeof(int));
            merged[mergedCount][0] = intervals[i][0];
            merged[mergedCount][1] = intervals[i][1];
            mergedCount++;
        } 
        else 
        {
            if (merged[mergedCount - 1][1] < intervals[i][1]) 
            {
                merged[mergedCount - 1][1] = intervals[i][1];
            }
        }
    }
    *returnSize = mergedCount;
    *returnColumnSizes = (int*)malloc(mergedCount * sizeof(int));
    for (int i = 0; i < mergedCount; i++) 
    {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}
int main() 
{
    int intervalsSize = 4;
    int intervalsColSize[] = {2, 2, 2, 2};
    int **intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) 
    {
        intervals[i] = (int*)malloc(2 * sizeof(int));
    }
    intervals[0][0] = 1; intervals[0][1] = 3;
    intervals[1][0] = 2; intervals[1][1] = 6;
    intervals[2][0] = 8; intervals[2][1] = 10;
    intervals[3][0] = 15; intervals[3][1] = 18;
    int returnSize;
    int *returnColumnSizes;
    int **mergedIntervals = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);
    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("[%d, %d]\n", mergedIntervals[i][0], mergedIntervals[i][1]);
        free(mergedIntervals[i]);
    }
    
    free(mergedIntervals);
    for (int i = 0; i < intervalsSize; i++) 
    {
        free(intervals[i]);
    }
    free(intervals);
    return 0;
}
