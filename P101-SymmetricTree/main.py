#
# LeetCode
# Algorithm 101 Symmetric Tree
#
# See LICENSE
#

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def traverse(self, left, right):
        if (left == None) and (right <> None):
            return False
        elif (left <> None) and (right == None):
            return False
        elif (left == None) and (right == None):
            return True
        elif left.val <> right.val:
            return False
        else:
            return self.traverse(left.left, right.right) and self.traverse(left.right, right.left)

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        else:
            return self.traverse(root.left, root.right)
