# Leetcode 605 Can Place Flowers

# Easy 

'''
Description: 
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
'''

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int planted = 0;
        # Iterate through the array, checking if the current spot is empty
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0) {
                # Check index before and after, including edge cases
                if ((i == 0 || flowerbed[i - 1] == 0) && ((i == flowerbed.length - 1 || flowerbed[i + 1] == 0))) {
                    planted++;
                    flowerbed[i] = 1;
                    i++;
                }
            }
        }
        # Can we plant n new flowers in the flowerbed?
        return planted >= n;
    }
}
