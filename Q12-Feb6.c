void moveZeroes(int* nums, int numsSize) {
    int nonzero=0;
    for(int i=0; i< numsSize; i++)
    {
        if(nums[i]!=0)
        {
            nums[nonzero] = nums[i];
            nonzero++;
        }
    }
    for(int i= nonzero; i<numsSize; i++)
    {
        nums[i]=0;
    }
}