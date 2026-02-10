int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size > nums2Size) {
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    }
    int map[1001] = {0};
    for (int i = 0; i < nums1Size; i++) 
    {
        map[nums1[i]]++;
    }
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (map[nums2[i]] > 0) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;
            map[nums2[i]]--;  
        }
    }
    return result;
}