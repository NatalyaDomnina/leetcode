'''
Given an integer array with no duplicates. A maximum tree building 
on this array is defined as follow:
The root is the maximum number in the array. The left subtree is 
the maximum tree constructed from left part subarray divided by 
the maximum number. The right subtree is the maximum tree constructed 
from right part subarray divided by the maximum number. Construct the 
maximum tree by the given array and output the root node of this tree.
'''
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def printTree(self):
        print(self.val)
        if self.left != None:
            self.left.printTree()
        if self.right != None:
            self.right.printTree()

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        t1 = TreeNode(max(nums))
        if len(nums) == 1:
            t1 = TreeNode(max(nums))
            return t1
        if len(nums[0:nums.index(max(nums))]) > 0:
            t1.left = self.constructMaximumBinaryTree(nums[0:nums.index(max(nums))])
        if len(nums[nums.index(max(nums))+1:]) > 0:
            t1.right = self.constructMaximumBinaryTree(nums[nums.index(max(nums))+1:])
        return t1

l = [3,2,1,6,0,5]
s = Solution()
s.constructMaximumBinaryTree(l).printTree()