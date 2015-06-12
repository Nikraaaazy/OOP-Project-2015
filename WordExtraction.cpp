#include "WordExtraction.h"
#include "Word.h"
#include "WordCollection.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

WordExtraction::WordExtraction(string path): inputPath(path) { }

void WordExtraction::extract()
{
	ifstream in;
	ofstream out;

	in.open(inputPath);
	out.open("Output-" + inputPath);

	string temp;
	vector<Word*> collection = WordCollection::instance -> getWordCollection();
	bool found = false;
	bool first = false;
	int counter = 0;
	vector<string> q;

	while(in >> temp)
	{
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		int index = 0;
		int l = 0, r = WordCollection::totalNum;

		while(l <= r)
		{
			int m = (l + r) / 2;
			if (temp == collection[m] -> getWord())
			{
				found = true;
				index = m;
				counter ++;
				if (find(q.begin(), q.end(), temp) == q.end())
					first = true;
				q.push_back(temp);
				break;
			}
			else if (temp > collection[m] -> getWord())
				l = m + 1;
			else if (temp < collection[m] -> getWord())
				r = m - 1;
		}
		if (found && first)
		{
			out << "******** Word No." << counter << " ********" << endl;
			out << collection[index] -> getWord() << endl;
			out << collection[index] -> getAll() << endl;
			out << endl;
			found = false;
			first = false;
		}

	}
	out.close();
	in.close();
}


