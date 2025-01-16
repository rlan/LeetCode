# Runtime 0 ms Beats 100.00%
# Memory 18.27 MB Beats 47.75%
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        end = len(nums)
        start = 0
        stop = False
        while not stop:
            center = (start + end) // 2
            stop = (start + 1 == end)
            #print(start, center, end)
            if nums[center] == target:
                return center
            elif target < nums[center]:
                end = center
            else:
                start = center

        return end
