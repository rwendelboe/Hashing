#ifndef GIVENWORD_H
#define GIVENWORD_H
#include <iostream>
#include <vector>
#include "FollowingWord.h"

using namespace std;

struct GivenWord
{
	string word;
	int count;
	vector<FollowingWord> secondWordList;
	string toString();
	GivenWord(string s, int c);
	void updateSecondWord(string w);//ask teacher
};
#endif