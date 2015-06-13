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
#include "WordRelative.h"
using namespace std;

int main()
{
	string command;
	string word;
	cout << "Welcome to my domain" << endl << endl;

	cout << "To find help, type help" << endl;
	cout << "To search, type search" << endl;
	cout << "To study, type study" << endl;
	cout << "To extract from file, type extract" << endl;
	cout << "To generate word relative map, type map" << endl;
	cout << "To exit, type exit" << endl;
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
			delete extractor;
			cout << "Explaination file exported at Output-" + path << endl << endl;
		}
		else if (command == "map")
		{
			string word;
			cout << "Your word: ";
			cin >> word;
			cout << word << " relates to : " << endl;
			WordRelative* relative = new WordRelative(word);
			relative -> generateRelative();
			delete relative;
			cout << endl;
		}
		else if (command == "help")
		{
			cout << "To find help, type help" << endl;
			cout << "To search, type search" << endl;
			cout << "To study, type study" << endl;
			cout << "To extract from file, type extract" << endl;
			cout << "To generate word relative map, type map" << endl;
			cout << "To exit, type exit" << endl;
			cout << endl;
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