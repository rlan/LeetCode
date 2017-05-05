#
# LeetCode
# Algorithm 119 Pascal's triangle II
#
# Rick Lan, May 5, 2017.
# See LICENSE
#
# Test case(s):
# -1
# 0
# 1
# 2
# 3
# 
# Your runtime beats 45.02 % of python submissions.
#

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        
        Compute in-place.
        Space use: O(k)
        """
        
        tri = [1]
        if rowIndex >= 1:
            i = 1
            while i <= rowIndex:
                tri.append(0)
                delay = 0
                for idx, val in enumerate(tri):
                    tri[idx] = val + delay
                    delay = val
                    
                #print(i, tri)
                i = i+1
            
            
        return tri