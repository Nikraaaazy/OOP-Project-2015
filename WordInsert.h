#ifndef WORDINSERT_H
#define WORDINSERT_H
#include<fstream>
#include<iostream>
#include "Word.h"
#include "WordCollection.h"
using namespace std;
class WordInsert{
	private:
		char* path;
		WordCollection* collection;
	public:
		WordInsert(){
			path=new char[100];
			collection=new WordCollection;
		}
		WordInsert(char* s,WordCollection* p){
			path = s;
			collection = p;
		}
		WordInsert(string str,WordCollection* p){
			path=str.c_str();
			collection = p;
		}
		~WordInsert(){}
		void Get_in();
		WordCollection* getWordCollection(){
			return collection;
		}
};
#endif
