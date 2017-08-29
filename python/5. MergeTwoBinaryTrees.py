'''
Given two binary trees and imagine that when you put one of them to cover the 
other, some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two 
nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.
Example:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
'''

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def add_left(self, x):
        self.left = x 
    def add_right(self, x):
        self.right = x
    def printTree(self):
        print(self.val)
        if self.left != None:
            self.left.printTree()
        if self.right != None:
            self.right.printTree()  

class Solution(object):
    def mergeTrees(self, t1, t2):
        if t1 == None:
            return t2
        if t2 == None:
            return t1
        t1.val = t1.val + t2.val
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right)
        return t1
        
#######################################################################

t1 = TreeNode(1)
t2 = TreeNode(3)
t4 = TreeNode(5)
t3 = TreeNode(2)

t2.add_left(t4)
t1.add_left(t2)
t1.add_right(t3)

print (t1.printTree())

t5 = TreeNode(2)
t6 = TreeNode(1)
t7 = TreeNode(4)
t8 = TreeNode(3)
t9 = TreeNode(7)

t6.add_right(t7)
t5.add_left(t6)
t8.add_right(t9)
t5.add_right(t8)

print (t5.printTree())

s = Solution()
t10 = s.mergeTrees(t1, t5)
print (t10.printTree())

