/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {		
		sort(nums.begin(), nums.end());
		vector <int> res;
        for (int i = 0; i < (int)nums.size()-1; i++) {
			if (nums[i] == nums[i+1]) {
				res.push_back(nums[i]);
			}
		}
		return res;
    }
};

int main() { 	
	Solution s;
	int arr[] = {1,5,4,6,7,5,1,2,4};
	vector<int> vec(arr, arr+9), res;
	res = s.findDuplicates(vec);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	getchar();
	return 0; 
}