/*
Given a positive integer, output its complement number. The complement
strategy is to flip the bits of its binary representation.
Note:
1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.
*/

#include "stdafx.h" 
#include <iostream> 
#include <bitset>

using namespace std;

class Solution {
public:
    int findComplement(int num) {		
		string snum = bitset<32>(num).to_string();
		int i = 0;
		while (snum[i] == '0') {
			i++;
		}
		snum = snum.substr(i);
		for (int i = 0; i < snum.length(); i++) {
			snum[i] = snum[i] ^ 1;
		}
        return stoi(snum, nullptr, 2);
    }
};

int main() { 
	Solution s;
	cout << s.findComplement(5);
	getchar();
	return 0; 
}