# Runtime 1692 ms Beats 27.66%
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for ii in range(0, length):
            for jj in range(ii+1, length):
                if nums[ii] + nums[jj] == target:
                    return [ii, jj]
                else:
                    continue
