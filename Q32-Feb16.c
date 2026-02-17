void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;  // Handle cases where k > numsSize
    int rotate[numsSize];
    
    for(int i = 0; i < numsSize; i++) {
        rotate[(i + k) % numsSize] = nums[i];
    }
    
    for(int i = 0; i < numsSize; i++) {
        nums[i] = rotate[i];
    }
}