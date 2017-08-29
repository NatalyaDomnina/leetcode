/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, 
judge if this robot makes a circle, which means it moves back to the original 
place. The move sequence is represented by a string. And each move is represent 
by a character. The valid robot moves are R (Right), L (Left), U (Up) and 
D (down). The output should be true or false representing whether the robot 
makes a circle.
*/

#include "stdafx.h" 
#include <iostream> 

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        if (count(moves.begin(), moves.end(), 'U')  == count(moves.begin(), moves.end(), 'D'))
			if (count(moves.begin(), moves.end(), 'L')  == count(moves.begin(), moves.end(), 'R'))
				return true;
			else return false;
		else return false;
    }
};

int main() { 
	string str = "UD";
	Solution obj;
	cout << obj.judgeCircle(str);
	getchar();
	return 0; 
}