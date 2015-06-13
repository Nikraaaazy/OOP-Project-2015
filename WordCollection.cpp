#include "WordCollection.h"
#include <fstream>
#include <cmath>

string WordCollection::path = "Output.txt";

int WordCollection::totalNum = 21451;

WordCollection* WordCollection::instance = new WordCollection(WordCollection::path);
WordCollection::WordCollection(string path)
{
	string dict[8] = {"0", "1", "2", "3", "4", "5", "6", "7"};

	cout << "Loading" << endl;

	ifstream in;
	string word;
	string all;
	int level;
	string l;
	string temp;

	in.open(path.c_str());

	while (!in.eof())
	{
		getline(in, word);
		getline(in, all);
		getline(in, l);
		getline(in, temp);
		for (int i = 0; i < 8; i++)
		{
			if (l == dict[i])
				level = i;
		}

		Word* next = new Word(word, all, level);
		collection.push_back(next);

	}

	cout << "Complete" << endl;

	in.close();
	No = 0;
}

WordCollection::WordCollection(WordCollection& collection)
{
	this -> collection = collection.collection;
	this -> No = collection.No;
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

void WordCollection::saveProgress(string path)
{
	ofstream out;
	out.open(path.c_str());

	vector<Word*> collection = WordCollection::instance -> getWordCollection();

	for (int i = 0; i < totalNum; i++)
	{
		out << (collection[i] -> getWord()) << endl;
		out << (collection[i] -> getAll()) << endl;
		out << (collection[i] -> getWordLevel()) << endl;
		out << endl;
	}
	out.close();
}






