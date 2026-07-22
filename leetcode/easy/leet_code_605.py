# Leetcode 605 Can Place Flowers

# Easy 
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
