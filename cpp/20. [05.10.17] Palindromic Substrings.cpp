/*
Given a string, your task is to count how many palindromic
substrings in this string. The substrings with different
start indexes or end indexes are counted as different
substrings even they consist of same characters.
*/

#include "stdafx.h" 
#include <iostream> 
#include <string> 

using namespace std;

class Solution {
public:
	bool reverse (string st) {
		int res = 0;
		for (int i = 0; i < st.size()/2; i++) {
			if (st[i] == st[st.size()-1-i]) res++;
			else break;
		}
		if (res == st.size()/2) 
			return true;
		else 
			return false;
	}
    int countSubstrings(string s) {
		if (s.size() == 1)
			return 1;
		int i = 0, j = 0, res = 0;
		while (true) {
			j = i + 1;
			for (int r = 0; r < s.size(); r++) {
				string tmp(s.begin() + i, s.begin() + j);
				//cout << tmp << " " << reverse(tmp) << endl;
				if (reverse(&tmp)) res++;
				if (j < s.size()) j++;
				else { i++; break; }
			}
			if (i == s.size()) break;		
		}
		return res;
    }
};

int main() { 	
	string str = "aba";
	Solution s;	
	cout<< s.countSubstrings(str);
	getchar();
	return 0; 
}