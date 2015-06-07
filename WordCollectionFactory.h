#ifndef WORDCOLLECTIONFACTORY_H
#define WORDCOLLECTIONFACTORY_H
#include "WordCollection.h"
using namespace std;
class WordCollectionFactory{
	public:
		WordCollectionFactory(){
			collection=WordCollection::instance->getWordCollection();
		}
		~WordCollectionFactory(){
			if(!collection){
				delete collection;
			}
		}
		WordCollection* create(int num){
			int newword=num/3;
			int oldword=num-oldword;
			WordCollection* collections=new WordCollection;
			for(vector<Word*>::size_type i=0;i<collection.size();++i){
				if(collection[i]->getWordLevel()>0){
					if(oldword){
						collections->push(collection[i]);
						oldword--;
					}
					else if(!newword) break;
				}
				else{
					if(newword){
						collections->push(collection[i]);
						newword--;
					}
					else if(!oldword) break;
				}
			}
			return collections;
		}
	private:
		vector<Word*> collection;
};
#endif
