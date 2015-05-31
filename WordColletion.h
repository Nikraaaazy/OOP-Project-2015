#ifndef WORD_COLLECTION_H
#define WORD_COLLECTION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Word;

class WordCollection
{
private:
	vector<Word*> collection;
public:
	WordCollection(string path);
	WordCollection(WordCollection& collection);
	~WordCollection();
	
};

#endif