#
# LeetCode
# Algorithm 121 Best Time to Buy and Sell Stock
#
# Rick Lan, May 5, 2017.
# See LICENSE
#
# Your runtime beats 29.10 % of python submissions.
#

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        
        Anchor the low and calculate profit if new price is higher. Remember if it is a
        new best profit.
        If new price drops lower than anchor, update the anchor.
        """
        
        n = len(prices)
        if n <= 1:
            return int(0)
            
        maxGain = 0
        low = prices[0]
        i = 1

        while i <= n-1:
            if prices[i] <= low:
                low = prices[i]
                i = i+1
            else:
                gain = prices[i] - low
                if gain > maxGain:
                    maxGain = gain
                i = i+1
            

        return maxGain
