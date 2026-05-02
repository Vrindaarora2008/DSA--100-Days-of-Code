/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) 
{
    if (intervalsSize == 0) return 0;
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int *endTimes = (int*)malloc(sizeof(int) * intervalsSize);
    int endTimesSize = 0;
    endTimes[endTimesSize++] = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) 
    {
        if (intervals[i][0] >= endTimes[0]) 
        {
            endTimes[0] = intervals[i][1];
        } 
        else 
        {
            endTimes[endTimesSize++] = intervals[i][1];
        }
        for (int j = (endTimesSize - 2) / 2; j >= 0; j--) 
        {
            int smallest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            if (left < endTimesSize && endTimes[left] < endTimes[smallest]) smallest = left;
            if (right < endTimesSize && endTimes[right] < endTimes[smallest]) smallest = right;
            if (smallest != j) {
                int temp = endTimes[j];
                endTimes[j] = endTimes[smallest];
                endTimes[smallest] = temp;
            }
        }
    }
    free(endTimes);
    return endTimesSize;
}
int main() 
{
    int intervalsSize = 3;
    int intervalsColSize[] = {2, 2, 2};
    int** intervals = (int**)malloc(sizeof(int*) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int*)malloc(sizeof(int) * intervalsColSize[i]);
    }
    intervals[0][0] = 0; intervals[0][1] = 30;
    intervals[1][0] = 5; intervals[1][1] = 10;
    intervals[2][0] = 15; intervals[2][1] = 20;
    int result = minMeetingRooms(intervals, intervalsSize, intervalsColSize);
    printf("Minimum number of rooms required: %d\n", result);
    for (int i = 0; i < intervalsSize; i++) 
    {
        free(intervals[i]);
    }
    free(intervals);
    return 0;
}
