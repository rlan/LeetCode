#
# LeetCode
# Algorithm 125 Valid Palindrome
#
# Rick Lan, May 6, 2017.
# See LICENSE
#
# Test case(s):
# ""
# "1"
# ";-="
# "A man, a plan, a canal: Panama"
# "race a car"
#
# Your runtime beats 51.13 % of python submissions.
#

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) <= 1:
            return True

        ignore = set(string.punctuation)
        ignore.add(' ')
        #print(ignore)

        n = len(s)
        front = 0
        back = n-1
        s_lo = s.lower()
        print(s_lo)
        # take care of string with all punctuations
        while (front < n) and (s_lo[front] in ignore):
            front = front + 1
        while (back >= 0) and (s_lo[back] in ignore):
            back = back - 1
        if front > back:
            return True

        while back-front >= 0:
            #print(s_lo[front], s_lo[back])
            if s_lo[front] <> s_lo[back]:
                return False
            front = front + 1
            while (front < n) and (s_lo[front] in ignore):
                front = front + 1
            back = back - 1
            while (back >= 0) and (s_lo[back] in ignore):
                back = back - 1


        return True
