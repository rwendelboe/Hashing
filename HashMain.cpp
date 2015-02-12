#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "FollowingWord.h"
#include "GivenWord.h"

using namespace std;

void readFile( HashTable<string, GivenWord> & table, string fileName ){
	ifstream fin(fileName);
	string givenWord, followingWord;
	

	fin >> givenWord;

	for (int i = 0; i < givenWord.length();)
	{
		if (givenWord[i] >255 || givenWord[i] < 0 || ispunct(givenWord[i]))
			givenWord.erase(i, 1);
		else{
			givenWord[i] = tolower(givenWord[i]);
			i++;
		}
	}

	while (fin >> followingWord){
		for (int i = 0; i < followingWord.length();)
		{
			if (followingWord[i] >255 || followingWord[i] < 0 || ispunct(followingWord[i]))
				followingWord.erase(i, 1);
			else{
				followingWord[i] = tolower(followingWord[i]);
				i++;
			}
		}
		
		GivenWord firstWord(givenWord, 1);

		GivenWord * record = table.find(firstWord.word);

		if (record == NULL){
			record = new GivenWord(givenWord, 1);
			table.insert(firstWord.word, record);
		}
		else{
			record->count++;
		}
		
		record->updateSecondWord(followingWord);

		givenWord = followingWord;
	}
	fin.close();
}

int main(){
	HashTable<string, GivenWord> test;
	

	//uncomment to test
	readFile(test, "green.txt");
	cout << test.toString() << endl;
	string gh = "sam";
	test.probability(gh, 20);

	////uncomment to test 
	//readFile(test, "clown.txt");
	//cout << test.toString(20) << endl;
	//string gh = "go";
	//test.probability(gh, 20);

	////uncomment to test
	//readFile(test, "inch.txt");
	//string gh = "computer";
	//test.probability(gh, 50);

	////uncomment to test
	//readFile(test, "Poe.txt");
	//cout << test.toString() << endl;
	//string gh = "nevermore";
	//test.probability(gh, 50);

	////uncomment to test
	//readFile(test, "Seuss.txt");
	//cout << test.toString() << endl;
	//string gh = "mordecai";
	//test.probability(gh, 50);


	cin.get();
	return 0;
}