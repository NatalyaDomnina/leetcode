/*
You need to find the largest value in each row of a binary tree.
Input: 
          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <queue>

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
private:
    vector<int> res;
	int width;
public:
	Solution(): width(1) {}
    vector<int> largestValues(TreeNode* root) {
		if (root == NULL)
			return res;
        
		if (res.size() < width)
            res.push_back(root -> val);
        else
            if (root -> val > res[width-1])
                res[width-1] = root -> val;
        
		width++;
        largestValues(root -> left);
        largestValues(root -> right);
		width--;
        
		return res;
    } 
};

int main() { 	
	TreeNode t4(4);
	TreeNode t5(7);
	TreeNode t6(3, &t5, &t4);
	TreeNode t7(9);
	TreeNode t8(2, 'r', &t7);
	TreeNode t9(1, &t6, &t8);

	vector<int> res;

	Solution s;	
	res =  s.largestValues(&t9);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	getchar();
	return 0; 
}