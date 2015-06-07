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
	int No;///�����ڼ��������� 
public:
	static WordCollection* instance;///Ψһ��һ���洢�����е��ʵ�collection 
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
		collection->push_back(s);
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
WordCollection::WordCollection* instance=new WordCollection("Output.txt")
#endif
