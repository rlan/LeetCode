#
# LeetCode
# Algorithm 118 Pascal's triangle
#
# Rick Lan, May 5, 2017.
# See LICENSE
#
# Your runtime beats 66.75 % of python submissions.
#

class Solution(object):
    
    def nextRow(self, prev):
        """
        :type prev: List[int]
        :rtype: List[int]
        
        difference equation: y(n) = x(n) + x(n-1)
        """
        delay = 0
        row = []
        for val in prev:
            row.append(val + delay)
            delay = val
        
        row.append(delay)
        #print(row)
        return row
        
        
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        
        self.tri = []
        
        if numRows >= 1:
            self.tri.append([1])
        if numRows >= 2:
            self.tri.append([1,1])
        i = 3
        while i <= numRows:
            #print(i)
            self.tri.append(self.nextRow(self.tri[-1]))
            i = i+1
            
        return self.tri