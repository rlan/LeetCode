#
# LeetCode
# Algorithm 112 Path Sum
#
# Your runtime beats 62.80 % of python submissions.
#
# Rick Lan on May 5, 2017
# See LICENSE
#
# Test case(s):
# []
# 1
# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# 22
# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# 26
# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# 18
# [5,4,8,11,null,13,4,7,2,null,null,null,1]
# 17
#
# Output:
# false
# true
# true
# true
# false
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def traverse(self, node, depth):
        """
        Depth first traverse.
        
        :type node: TreeNode
        :type depth: int
        :rtype: None
        """
        if (node.left == None) and (node.right == None):
            if depth + node.val == self.sum:
                self.match = True
                
            return

        #print(node.val, depth)
        if node.left != None:
            self.traverse(node.left, depth+node.val)
        if node.right != None:
            self.traverse(node.right, depth+node.val)
        return
    

    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        
        if root == None:
            return False
        
        self.sum = sum
        self.match = False
        
        self.traverse(root, 0)
        return self.match
        