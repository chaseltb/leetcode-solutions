# 347 Top K Frequent Elements

# Medium O(n) time

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        # Return the k most common elements, according to the counter
        return [num for num, ans in counts.most_common(k)]

'''
Description:

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
'''
