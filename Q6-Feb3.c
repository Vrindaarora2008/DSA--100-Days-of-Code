int missingNum(int *arr, int size) {
    int n = size + 1; 
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for(int i = 0; i < size; i++) 
    {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}