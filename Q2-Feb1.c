
int* twoSum(int* nums, int Size, int target, int* returnSize) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < Size - 1; i++) 
    {
        for (int j = i + 1; j < Size; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}