#ifndef __WordSearch__
#define __WordSearch__

//#include "  "
//#include "  "
//#include "  "
#include <iostream>
#include <cstring>
#include <vector>
#include "Word.h"
using namespace std;

class WordSearch
{
private:
	int Maxnum;
	string TargetWord;
	vector<Word*> collection;
public:
	WordSearch(string word);
	void binarySearch();
};

#endif
