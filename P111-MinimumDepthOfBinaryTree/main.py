#
# LeetCode
# Algorithm 111 Minimum Depth of Binary Tree
#
# Your runtime beats 8.00 % of python submissions.
#
# See LICENSE
#

# Test cases:
# []
# [1]
# [1,2]
# [1,2,3]
# [1,2,3,4]
# [1,2,3,4,5]
# [1,2,3,4,5,6]
# [1,2,3,4,5,6,7]
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
            if self.minDepth == None:
                self.minDepth = depth
            elif depth < self.minDepth:
                self.minDepth = depth
            #print('Depth', depth, self.minDepth)                
            return

        #print(node.val)
        if node.left != None:
            self.traverse(node.left, depth+1)
        if node.right != None:
            self.traverse(node.right, depth+1)
        return
    
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return int(0)
            
        self.minDepth = None;
        self.traverse(root, 1)
        return self.minDepth
