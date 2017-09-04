/*
Given a List of words, return the words that can be typed using letters
of alphabet on only one row's of American keyboard
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
		vector <string> out_words;
		string str1 = "qwertyuiop";
		string str2 = "asdfghjkl";
		string str3 = "zxcvbnm";

		for (int i = 0; i < words.size(); i++) {
			int res1 = 0, res2 = 0, res3 = 0;
			for (int j = 0; j < words[i].size(); j++) {
				char tmp = char(tolower(words[i][j]));
				if (str1.find(tmp) <= str1.size()) res1++;
				if (str2.find(tmp) <= str2.size()) res2++;
				if (str3.find(tmp) <= str3.size()) res3++;
			}
			if (res1 == words[i].size() || res2 == words[i].size() || res3 == words[i].size())
				out_words.push_back(words[i]);
		}
		return out_words;
    }
};

int main() { 
	vector <string> l;
	l.push_back("Hello");
	l.push_back("Alaska");
	l.push_back("Dad");
	l.push_back("Peace");

	Solution s;
	vector <string> res =  s.findWords(l);
	for (int i = 0; i < res.size(); i++) {
		cout << res.at(i) << ' ';
	}

	getchar();
	return 0; 
}