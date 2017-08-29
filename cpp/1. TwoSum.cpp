/*
Given an array of integers, return indices of the two numbers such that they 
add up to a specific target. You may assume that each input would have exactly 
one solution, and you may not use the same element twice.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
		for (int i = 0; i < nums.size()-1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					res.push_back(i);
					res.push_back(j);
					cout << res[0] << " " << res[1] << endl;
					getchar();
					return res;
				}
			}
		}
    }
};

int main() { 
	int arr[] = {0,2,4,0};
	vector <int> v(arr, arr + 3);
	int ch = 6;
	Solution obj;
	obj.twoSum(v, ch);
	return 0; 
}