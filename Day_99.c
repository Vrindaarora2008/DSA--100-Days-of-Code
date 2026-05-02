/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);
    double time[n];
    for (int i = 0; i < n; i++) 
    {
        time[i] = (double)(target - position[i]) / speed[i];
    }
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (position[j] < position[j + 1]) 
            {
                int tempPos = position[j];
                position[j] = position[j + 1];
                position[j + 1] = tempPos;
                int tempSpeed = speed[j];
                speed[j] = speed[j + 1];
                speed[j + 1] = tempSpeed;
                double tempTime = time[j];
                time[j] = time[j + 1];
                time[j + 1] = tempTime;
            }
        }
    }
    int fleets = 0;
    double lastTime = -1.0;
    for (int i = 0; i < n; i++) 
    {
        if (time[i] > lastTime) 
        {
            fleets++;
            lastTime = time[i];
        }
    }
    printf("Number of car fleets: %d\n", fleets);
    return 0;
}