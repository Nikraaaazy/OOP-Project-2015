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
		in >> word;
		in >> all;
		in >> level;
		in >> temp;
		Word* next = new Word(word, all, level);
		collection.push_back(next);
	}

	in.close();
	No=0;
}

WordCollection::WordCollection(WordCollection& collection)
{
	this -> collection = collection.collection;
	this -> No = collection.num;
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
