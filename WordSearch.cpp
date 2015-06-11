//#include "  "
//#include "  "
//#include "  "
#include "WordSearch.h"
#include "WordCollection.h"


WordSearch::WordSearch(string word)
{
	collection = WordCollection::instance -> getWordCollection();
	Maxnum = WordCollection::instance -> size();
	TargetWord = word;
}

void WordSearch::binarySearch()
{
	//do something
	int l = 1, r = Maxnum;
	int m = (l + r) / 2;
	bool found = false;
	while (r - l > 10)
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
	if (!found)
		for (int i = l; i <= r; i++)
		{
			if ((collection[i] -> getWord()) == TargetWord)
			{
				m = i;
				found = true;
				break;
			}
		}
	if (found)
		cout << (collection[m] -> getAll()) << endl;
	else
		cout << "Cannot find this word!!!" << endl;
	//string Word::getWord();
	//string Word::getAll();
	//Word word[Maxnum];
}
