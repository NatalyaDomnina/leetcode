/*
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), where h 
is the height of the person and k is the number of people in 
front of this person who have a height greater than or equal 
to h. Write an algorithm to reconstruct the queue.
*/

#include "stdafx.h" 
#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if (people.size() < 2) {
            return people;
        }
		
		vector<pair<int, int>> res;
		vector<int> num;

        sort(people.begin(), people.end());
		reverse(people.begin(), people.end());

		for (int i = 0; i < people.size(); i++) {
            if ((count(num.begin(), num.end(), people[i].first) == 0 && people[i].first != people[0].first)) {
				num.push_back(people[i].first);
			}
		}

		int k = 0;
		while (people[k].first == people[0].first) { 
			res.push_back(people[k]);
            k++;
		}
		sort(res.begin(), res.end());

		for (int i = 0; i < num.size(); i++) {
			vector<pair<int, int>> tmp;
			for (int j = 0; j < people.size(); j++) {
				if (people[j].first == num[i]) {
					tmp.push_back(people[j]);
				}
			}
			sort(tmp.begin(), tmp.end());
			for (int j = 0; j < tmp.size(); j++) {				
				res.insert(res.begin() + tmp[j].second, tmp[j]);
			}
		}
		return res;
    }
};

int main() { 
	pair<int,int> p1 = make_pair(7,0);
	pair<int,int> p2 = make_pair(4,4);
	pair<int,int> p3 = make_pair(7,1);
	pair<int,int> p4 = make_pair(5,0);
	pair<int,int> p5 = make_pair(6,1);
	pair<int,int> p6 = make_pair(5,2);

	vector<pair<int, int>> vec, res;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	vec.push_back(p5);
	vec.push_back(p6);

	Solution s;	
	res = s.reconstructQueue(vec);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << "," << res[i].second << ' ';
	}
	getchar();
	return 0; 
}