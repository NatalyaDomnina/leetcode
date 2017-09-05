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
#include <string>  

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
		int res = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'X') {
					if (i == 0 || board[i-1][j] == '.') {
						if (j == 0 || board[i][j-1] == '.') {
							res++;
						}
					}
				}
			}
		}
		return res;
	}
	
	vector<char> push (string a) {
		vector <char> vec;
		for (int i = 0; i < a.length(); i++) {
			vec.push_back(a.at(i));
		}
		return vec;
	}
};

int main() { 
	Solution s;
	vector<vector<char>> vec;
	string a[] = {"X...", 
				  "X..X", 
				  "....", 
				  "X..X"};
	int count = sizeof(a)/sizeof(a[0]);
	
	for (int i = 0; i < count; i++) {
		vec.push_back(s.push(a[i]));
	}
	
	cout << s.countBattleships(vec);
	getchar();
	return 0; 
}