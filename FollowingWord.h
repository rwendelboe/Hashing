#ifndef FOLLOWINGWORD_H
#define	FOLLOWINGWORD_H
#include <iostream>

using namespace std;

struct FollowingWord
{
	string word;
	int count;
	string toString();
	FollowingWord(string s, int c);
};
#endif