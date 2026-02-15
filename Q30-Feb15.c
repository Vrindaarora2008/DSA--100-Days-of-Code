void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int columns = matrixColSize[0];
    bool firstCol = false;

    for(int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0) 
            firstCol = true; 

        for (int j = 1; j < columns; j++) 
        { 
            if (matrix[i][j] == 0) 
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for (int i = rows - 1; i >= 0; i--) 
    { 
        for (int j = columns - 1; j >= 1; j--) 
        { 
            if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                matrix[i][j] = 0; 
        } 

        if (firstCol) 
            matrix[i][0] = 0; 
    }
}
