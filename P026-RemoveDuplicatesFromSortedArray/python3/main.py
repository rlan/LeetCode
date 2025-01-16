# Runtime 3 ms Beats 49.88%
# Memory 19.05 MB Beats 16.12%
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        anchor = 0
        for walk in range(1, len(nums)):
            if not nums[anchor] == nums[walk]:
                anchor = anchor + 1
                nums[anchor] = nums[walk]

        return anchor + 1