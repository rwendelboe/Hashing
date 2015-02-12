#include "GivenWord.h"

GivenWord::GivenWord(string s, int c){
	word = s;
	count = c;
}

string GivenWord::toString(){
	return word;
}

void GivenWord::updateSecondWord(string w){
	bool isInVector = false;

	for (int i = 0; i < secondWordList.size(); ++i){
		if (w == secondWordList.at(i).word){
			secondWordList.at(i).count++;
			isInVector = true;
		}
	}
	if (!isInVector){
		FollowingWord followW(w, 1);
		secondWordList.push_back(followW);
	}
}