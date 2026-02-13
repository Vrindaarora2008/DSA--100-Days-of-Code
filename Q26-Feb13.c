int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if(matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    *returnSize = rows * cols;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    int index = 0;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while(top <= bottom && left <= right) {
        // Traverse right along top row
        for(int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;  // Move top boundary down
        
        // Traverse down along right column
        for(int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;  // Move right boundary left
        
        // Traverse left along bottom row (if still valid)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;  // Move bottom boundary up
        }
        
        // Traverse up along left column (if still valid)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;  // Move left boundary right
        }
    }
    
    return result;
}