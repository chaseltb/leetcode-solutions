# 347 Top K Frequent Elements

# Medium O(n) time
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        # Return the k most common elements, according to the counter
        return [num for num, ans in counts.most_common(k)]
