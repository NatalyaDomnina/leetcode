/*
The Hamming distance between two integers is the number of 
positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		string a, b;
		int i = 0, res = 0;
        while (x > 0 || y > 0) {
			if (x > 0) {
				a += to_string(x % 2);
				x /= 2;
			}

			if (y > 0) {
				b += to_string(y % 2);
				y /= 2;
			}

			if (x > 0 & y == 0) {
				b += "0";
			}

			if (y > 0 & x == 0) {
				a += "0";
			}

			if (a[i] != b[i]) res++;
			i++;
		}

		return res;
    }
};

int main() { 
	Solution obj;
	cout << obj.hammingDistance(1, 4) << endl;
	getchar();
	return 0; 
}