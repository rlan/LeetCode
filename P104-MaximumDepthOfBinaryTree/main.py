#
# LeetCode
# Algorithm 104 Maximum depth of binary tree
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
    def traverse(self, root, depth):
        """
        :type root: TreeNode
        :type depth: int
        :rtype: int
        """
        if root == None:
            return depth
        else:
            return max( self.traverse(root.left, depth+1), self.traverse(root.right, depth+1))

    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.traverse(root, 0)
