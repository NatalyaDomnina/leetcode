/*
Given an integer array with no duplicates. A maximum tree building 
on this array is defined as follow:
The root is the maximum number in the array. The left subtree is 
the maximum tree constructed from left part subarray divided by 
the maximum number. The right subtree is the maximum tree constructed 
from right part subarray divided by the maximum number. Construct the 
maximum tree by the given array and output the root node of this tree.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <algorithm>  

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	void printTree() {
		cout << val << endl;
		if (left != NULL)
			left -> printTree();
		if (right != NULL)
			right -> printTree();
	}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode *t1 = new TreeNode(*max_element(nums.begin(), nums.end()));
		vector <int> nums_left;
		vector <int> nums_right;
		int max = *max_element(nums.begin(), nums.end());
		int max_el = find(nums.begin(), nums.end(), max) - nums.begin();
		if (nums.size() == 0) {
			return t1;
		}
		for (int i = 0; i < max_el; i++){
			nums_left.push_back(nums[i]);
		}
		
		if (nums_left.size() > 0) {
			t1 -> left = constructMaximumBinaryTree(nums_left);
		}
		if (max_el + 1 < nums.size()) {
			for (int i = max_el + 1; i < nums.size(); i++){
				nums_right.push_back(nums[i]);
			}
		}
		
		if (nums_right.size() > 0) {
			t1 -> right = constructMaximumBinaryTree(nums_right);
		}
		cout << t1->val;
		return t1;
    }
};

int main() { 
	int arr[] = {3,2,1,6,0,5};
	vector <int> vec (arr, arr + 6);
	Solution s;
	TreeNode t1(0);
	s.constructMaximumBinaryTree(vec);
	getchar();
	return 0; 
}