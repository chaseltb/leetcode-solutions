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

'''
Description:

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
'''
