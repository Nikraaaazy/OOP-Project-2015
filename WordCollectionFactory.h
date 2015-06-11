#ifndef WORDCOLLECTIONFACTORY_H
#define WORDCOLLECTIONFACTORY_H
#include "WordCollection.h"
using namespace std;
class WordCollectionFactory{
	public:
		WordCollectionFactory()
		{
			collection = WordCollection::instance->getWordCollection();
		}

		WordCollection* create(int num)
		{
			int newWord = num/3;
			int oldWord = num-newWord;
			WordCollection* collections = new WordCollection;
			for(vector<Word*>::size_type i = 0; i < collection.size(); ++i)
			{
				if(collection[i]->getWordLevel()>0)
				{
					if(oldWord)
					{
						collections->push(collection[i]);
						oldWord--;
					}
					else if(!newWord) break;
				}
				else
				{
					if(newWord)
					{
						collections->push(collection[i]);
						newWord--;
					}
					else if(!oldWord) break;
				}
			}
			return collections;
		}
	private:
		vector<Word*> collection;
};
#endif
