#
# LeetCode
# Algorithm 108 Convert Sorted Array to Binary Search Tree
#
# Your runtime beats 91.67 % of python submissions.
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
#


class Solution(object):

    def traverse(self, node):
        """
        :type node: TreeNode
        :rtype: None
        """
        if node == None:
            return
        
        print(node.val)
        self.traverse(node.left)
        self.traverse(node.right)
    
    def buildBST(self, nums, parent):
        """
        :type nums: List[int]
        :type parent: TreeNode
        :rtype: None
        """
        n = (len(nums)-1) / 2
        #print(n, nums)
        parent.val = nums[n]
        if n > 0:
            parent.left = TreeNode(0)
            self.buildBST(nums[:n], parent.left)
        
        if n+1 < len(nums):
            parent.right = TreeNode(0)
            self.buildBST(nums[n+1:], parent.right)
            
        return

    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        
        if (nums == None) or (len(nums) == 0):
            return None
            
        #print(sys.version_info)
            
        parent = TreeNode(0)
        #self.traverse(parent)
        
        self.buildBST(nums, parent)
        #self.traverse(parent)
        return parent
        