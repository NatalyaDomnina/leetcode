/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <string>  

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int posA = a.find('+'), posB = b.find('+');
		string as1, as2, bs1, bs2, res;
		int a1, a2, b1, b2, pr1, pr2;	

		for (int i = 0; i < a.length(); i++) {
			if (i < posA) as1 += a.at(i);
			if (i > posA) as2 += a.at(i);
		}

		for (int i = 0; i < b.length(); i++) {
			if (i < posB) bs1 += b.at(i);
			if (i > posB) bs2 += b.at(i);
		}

		a1 = atoi(as1.c_str());
		a2 = atoi(as2.c_str());
		b1 = atoi(bs1.c_str());
		b2 = atoi(bs2.c_str());

		pr1 = a1*b1 + a2*b2*(-1);
		pr2 = a1*b2 + a2*b1;

		res = to_string(pr1) + '+' + to_string(pr2) + 'i';
		return res;
	}
};

int main() { 
	string a = "1+-1i", b = "1+-1i";
	Solution s;
	cout << s.complexNumberMultiply(a,b);
	getchar();
	return 0; 
}