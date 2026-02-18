int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize;
    int* answer = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) 
    {
        answer[i] = 1;
    }
    int left = 1;
    for (int i = 0; i < numsSize; i++) 
    {
        answer[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) 
    {
        answer[i] *= right;
        right *= nums[i];
    }
    return answer;
}