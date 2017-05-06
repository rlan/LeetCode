#
# LeetCode
# Algorithm 155 Min Stack
#
# Rick Lan, May 6, 2017.
# See LICENSE
#
# Technique: Keep a parallel stack of running min values.
#
# Your runtime beats 97.31 % of python submissions.
#

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.mins = []


    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if len(self.mins) == 0:
            self.mins.append(x)
        else:
            if x < self.mins[-1]:
                self.mins.append(x)
            else:
                self.mins.append(self.mins[-1])


    def pop(self):
        """
        :rtype: void
        """
        self.data.pop()
        self.mins.pop()


    def top(self):
        """
        :rtype: int
        """
        if len(self.data) > 0:
            return self.data[-1]
        else:
            return None


    def getMin(self):
        """
        :rtype: int
        """
        if len(self.mins) > 0:
            return self.mins[-1]
        else:
            return None



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
