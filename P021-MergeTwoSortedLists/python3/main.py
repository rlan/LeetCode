# Runtime 0 ms Beats 100.00%
# Memory 17.82 MB Beats 19.42%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # corner cases
        if list1 == None:
            return list2
        elif list2 == None:
            return list1

        if list1.val <= list2.val:
            head = list1
            left = list1.next
            right = list2
        else:
            head = list2
            left = list2.next
            right = list1
        # merge
        ptr = head
        stop = (left == None) and (right == None)
        while not stop:
            if left == None:
                ptr.next = right
                right = right.next
            elif right == None:
                ptr.next = left
                left = left.next
            elif left.val <= right.val:
                ptr.next = left
                left = left.next
            else:
                ptr.next = right
                right = right.next

            ptr = ptr.next
            stop = (left == None) and (right == None)

        return head