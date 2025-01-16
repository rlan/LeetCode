# Runtime 0 ms Beats 100.00%
# Memory 17.79 MB Beats 27.37%
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
            
        start = 0
        end = len(nums) - 1
        while start < end:
            if nums[end] == val:
                end = end - 1
            elif nums[start] == val:
                nums[start] = nums[end]
                nums[end] = val
                start = start + 1
                end = end - 1
            else:
                start = start + 1

        if nums[start] == val:
            return start
        else:
            return start + 1
