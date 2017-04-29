#
# LeetCode
# Algorithm 107 Binary Tree Level Order Traversal II
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
    def add(self, depth, value):
        """
        depth start from 1

        :type index: int
        :type value: int
        :rtype: None
        """
        #print(self.depth, depth, value)
        if depth > self.depth:
            self.depth = depth
            self.order_list.insert(0, [value])  # insert at beginning
        else:
            index = len(self.order_list) - depth
            self.order_list[index].append(value)  # same level so append
        return

    def traverse(self, root, depth):
        """
        :type root: TreeNode
        :type depth: int
        :rtype: int
        """
        if root == None:
            return
        else:
            self.add(depth, root.val)
            self.traverse(root.left, depth+1)
            self.traverse(root.right, depth+1)
        return


    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """

        #print(type(root))
        if root == None:
            return []

        self.order_list = []
        self.depth = 0

        self.traverse(root, 1)
        return self.order_list
