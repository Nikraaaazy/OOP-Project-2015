#include "WordCollection.h"
#include <fstream>

WordCollection::WordCollection(string path)
{
	ifstream in;
	string word;
	string all;
	string level;
	string temp;

	in.open(path);

	while(!in.eof())
	{
		cin >> word;
		cin >> all;
		cin >> level;
		cin >> temp;
		Word* next = new Word(word, all, level);
		collection.push_back(next);
	}

	in.close();
}

WordCollection::WordCollection(WordCollection& collection)
{
	this -> collection = collection.collection;
}

WordCollection::~WordCollection()
{
	for (vector<Word*>::size_type i = 0; i < collection.size(); ++i)
	{
		Word *temp = collection.back();
		collection.pop_back();
		delete temp;
	}
}