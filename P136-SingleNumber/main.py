#
# LeetCode
# Algorithm 136 Single Number
#
# Rick Lan, May 6, 2017.
# See LICENSE
#
# Test case(s):
# [1]
# [0,2,0]
#
# Your runtime beats 83.04 % of python submissions.
#

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int

        A number XOR with itself will be zero.
        If with XOR every element in the array, then the result will be the single one.
        """
        secret = nums[0]
        for val in nums[1:]:
            secret = secret ^ val

        return secret
