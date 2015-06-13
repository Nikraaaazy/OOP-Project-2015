#include "WordRelative.h"

WordRelative::WordRelative(string word): word(word) { }

void WordRelative::generateRelative()
{
	multimap<int, string> relative;
	vector<Word*> collection = WordCollection::instance -> getWordCollection();

	for (int i = 0; i < WordCollection::totalNum; i ++)
	{
		int maxLength = 0;
		int length[50][50];
		for (int i = 0; i < 50; i++)
		{
			for(int j = 0; j < 50; j ++)
				length[i][j] = 0;
		}
		string compareWord = collection[i] -> getWord();
		for(string::size_type i = 0; i < word.size(); i ++)
		{
			for (string::size_type j = 0; j < compareWord.size(); j++)
			{
				if (word[i] == compareWord[j])
				{
					if (i && j)
						length[i][j] = length[i-1][j-1] + 1;
					else
						length[i][j] = 1;
					if (length[i][j] > maxLength)
						maxLength = length[i][j];
				}
			}
		}
		relative.insert(make_pair(maxLength, compareWord));
	}

	int counter = 0;
	multimap<int, string>::iterator i = relative.end();
	i --;
	while(counter != 9)
	{
		cout << i -> first << " " << i -> second << endl;
		i --;
		counter ++;
	}
}	