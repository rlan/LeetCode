#
# LeetCode
# Algorithm 160 Intersection of Two Linked Lists
#
# Rick Lan, May 8, 2017.
# See LICENSE
#
# Technique
#
# Start at pA = headA and pB = headB and increment both one step at a time.
# When either one reaches the end of the list, loop it to the other list.
# After each pointer loop once, they will reach both of the list at the end
# in the same number of steps, ie in m+n, where m is length of A and n of B.
#
# If the lists is not merged, then pA != pB for every step. If list is
# merged, then the first pA == pB is the start of the merged list. This
# works because cross loops will make the point with the shorter list first
# go to the longer list next, and vice versa, so the pointers will meet at
# the merged list.
#
# Time complexity: O(m+n)
# Space complexity: O(2)
#
# 42 / 42 test cases passed.
# Runtime: 438 ms
# Your runtime beats 60.94 % of python submissions.
#

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        pA = headA
        pB = headB
        count = 2

        while (pA != None) and (pB !=None):
            if pA == pB:
                return pA

            pA = pA.next
            pB = pB.next
            if (pA == None) and (count > 0):
                pA = headB
                count = count - 1
            if (pB == None) and (count > 0):
                pB = headA
                count = count - 1


        return None
