#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Word
{
private:
	string word; // word name
	string all;  // word all
	int wordLevel; // raw grey or done
public:
	Word(string word, string all, string wordLevel);
	Word(Word& word);
	string getWord();
	string getAll();
	int getWordLevel();
	void setWordLevel(int level);
	bool operator==(Word& word);
};