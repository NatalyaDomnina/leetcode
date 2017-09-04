/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes 
overlap, then sum node values up as the new value of the merged node. Otherwise, 
the NOT null node will be used as the node of new tree.
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
Note: The merging process must start from the root nodes of both trees.
*/

#include "stdafx.h" 
#include <iostream> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *y) : val(x), left(y), right(NULL) {}
	TreeNode(int x, char q, TreeNode *y) : val(x), left(NULL), right(y) {}
	TreeNode(int x, TreeNode *y, TreeNode *z) : val(x), left(y), right(z) {}
};

class Solution {
public:
	void printTree(TreeNode *x) {
		cout << x -> val << ' ';
		if (x -> left != NULL) {
			printTree(x -> left);
		}
		if (x -> right != NULL) {
			printTree(x -> right);
		}
	}

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
			return t2;
		}
		if (t2 == NULL) {
			return t1;
		}
		t1 -> val = t1 -> val + t2 -> val;
		t1 -> left = mergeTrees(t1 -> left, t2 -> left);
		t1 -> right = mergeTrees(t1 -> right, t2 -> right);
		return t1;
    }
};

int main() { 	
	// Tree 1
	TreeNode t1(5);
	TreeNode t2(3, &t1);
	TreeNode t3(2);
	TreeNode t4(1, &t2, &t3);	
	
	// Tree 2
	TreeNode t5(4);
	TreeNode t6(1, 'r', &t5);
	TreeNode t7(7);
	TreeNode t8(3, 'r', &t7);
	TreeNode t9(2, &t6, &t8);
	
	// show
	Solution s;
	s.printTree(&t4);
	cout << endl;
	s.printTree(&t9);

	// sum
	s.mergeTrees(&t4, &t9);	
	
	// show
	cout << endl;
	s.printTree(&t4);

	getchar();
	return 0; 
}