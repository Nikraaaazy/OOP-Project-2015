#ifndef WORD_COLLECTION_H
#define WORD_COLLECTION_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Word;

class WordCollection
{
private:
	vector<Word*> collection;
	int No;///背到第几个单词了 
public:
	static WordCollection* instance;///唯一的一个存储了所有单词的collection 
	WordCollection(){
		No=0;
	}
	WordCollection(string path);
	WordCollection(WordCollection& collection);
	~WordCollection();
	vector<Word*> getWordCollection(){
		return collection;
	}
	void push(Word* s){
		collection.push_back(s);
	}
	int size(){
		int s=(int)collection.size();
		return s;
	}
	bool isEmpty(){
		int siz=(int)collection.size();
		return No>siz-1;
	}
	Word* next(){
		if(!isEmpty()){
			return collection[No++];
		}
		else return NULL;
	}
};
WordCollection* WordCollection::instance=new WordCollection("Output.txt");
#endif