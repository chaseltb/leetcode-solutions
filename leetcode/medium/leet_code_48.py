# 48 Rotate Image (Constant Space)

# Rotate the matrix in place, not allocating another matrix.
# Medium O(1) Space, O(n^2) Time
import numpy as np

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
    
        # Iterate through the matrix, rotating it in place
        for i in range(n):
            for j in range(i, n):
                # Transpose the matrix
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            # Reverse the matrix
            matrix[i].reverse()            
