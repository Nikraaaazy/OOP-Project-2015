//#include "  "
//#include "  "
//#include "  "
#include "WordSearch.h"
#include "WordCollection.h"


WordSearch::WordSearch(string word)
{
	collection = WordCollection::instance -> getWordCollection();
	Maxnum = WordCollection::totalNum;
	TargetWord = word;
}

void WordSearch::binarySearch()
{
	//do something
	int l = 0, r = Maxnum;
	int m = (l + r) / 2;
	bool found = false;
	while (l <= r)
	{
		if ((collection[m] -> getWord()) == TargetWord)
		{
			found = true;
			break;
		}
		if ((collection[m] -> getWord()) > TargetWord)
			r = m - 1;
		if ((collection[m] -> getWord()) < TargetWord)
			l = m + 1;
		m = (l + r) / 2;
	}
	if (found)
		cout << (collection[m] -> getAll()) << endl;
	else
		cout << "Cannot find this word!!!" << endl;
	//string Word::getWord();
	//string Word::getAll();
	//Word word[Maxnum];
}
