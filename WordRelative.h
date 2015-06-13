#ifndef WORD_RELATIVE_H
#define WORD_RELATIVE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Word.h"
#include "WordCollection.h"

using namespace std;

class WordRelative
{
private:
	string word;
public:
	WordRelative(string word);
	void generateRelative();
};

#endif