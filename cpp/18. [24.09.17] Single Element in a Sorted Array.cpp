/*
Given a sorted array consisting of only integers where every element 
appears twice except for one element which appears once. Find this 
single element that appears only once.
Note: Your solution should run in O(log n) time and O(1) space.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];	

		int max_pos = nums.size()-1;
		int min_pos = 0;	
		int i;

		while (min_pos < max_pos) {
			i = min_pos + (max_pos - min_pos) / 2;
			if (i % 2 == 0) {
                if (nums[i] == nums[i-1]) max_pos = i - 2;
                else if (nums[i] == nums[i+1]) min_pos = i + 2;
                else return nums[i];
            }
            else {
                if (nums[i] == nums[i-1]) min_pos = i + 1;
                else if (nums[i] == nums[i+1]) max_pos = i - 1;
            }
        }
        return nums[min_pos];
	}
};

int main() { 
	int mas[] = {1,1,2,2,3,3,4,4,5,5,6,7,7,8,8};
	vector<int> vec (mas, mas + 15);
	Solution s;	
	cout << s.singleNonDuplicate(vec) << endl;
	getchar();
	return 0; 
}