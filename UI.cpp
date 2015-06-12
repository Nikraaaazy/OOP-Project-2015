#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#include "Word.h"
#include "WordCollection.h"
#include "WordCollectionFactory.h"
#include "WordSearch.h"
#include "WordTest.h"
#include "WordExtraction.h"
using namespace std;

int main()
{
	string command;
	string word;
	cout << "Welcome to my domain" << endl << endl;
	cout << "To search, input search" << endl;
	cout << "To study, input study" << endl;
	cout << "To extract from file, input extract" << endl;

	cout << "To exit, input exit" << endl;
	cout << endl;

	while (1)
	{
		cin >> command;
		if (command == "search")
		{
			cout << "search: ";
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			WordSearch* search = new WordSearch(word);
			search -> binarySearch();
			delete search;
			cout << endl;
		}
		else if (command == "study")
		{
			int num;
			cout << "How many words would you like?" << endl;
			cin >> num;
			cout << "Type \"Y / N\" for \"Know\" or \"Don't Know\"" << endl << endl;
			WordTest* test = new WordTest(num);
			test -> Test();
			delete test;
		}
		else if (command == "extract")
		{
			string path;
			cout << "Your file path: ";
			cin >> path;
			WordExtraction* extractor = new WordExtraction(path);
			extractor -> extract();
			cout << "Explaination file exported at Output-" + path << endl << endl;
		}
		else if (command == "exit")
		{
			WordCollection::saveProgress(WordCollection::path);
			exit(0);
		}
		else
			cout << "Command not recognized" << endl << endl;
	}



	return 0;
}