int maxSubarraySumCircular(int* nums, int numsSize) 
{
    int totalSum = 0, maxSum = nums[0], minSum = nums[0];
    int currMax = 0, currMin = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        totalSum += nums[i];    
        currMax = (currMax + nums[i] > nums[i]) ? currMax + nums[i] : nums[i];
        maxSum = (currMax > maxSum) ? currMax : maxSum;
        currMin = (currMin + nums[i] < nums[i]) ? currMin + nums[i] : nums[i];
        minSum = (currMin < minSum) ? currMin : minSum;
    }
    if (maxSum < 0) 
    return maxSum;
    int circularMax = totalSum - minSum;
    return (maxSum > circularMax) ? maxSum : circularMax;
}