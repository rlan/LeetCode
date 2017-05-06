#
# LeetCode
# Algorithm 141 Linked List Cycle
#
# Rick Lan, May 6, 2017.
# See LICENSE
#
# Your runtime beats 69.76 % of python submissions.
#
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if head == None:
            return False

        crash = ListNode(0)
        p = head
        p = p.next
        while p != None:
            if p == crash:
                return True
            next = p.next
            p.next = crash
            p = next

        return False
