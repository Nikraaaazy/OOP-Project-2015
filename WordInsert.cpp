#ifndef WORDINSERT_CPP
#define WORDINSERT_CPP
#include "WordInsert.h"
void WordInsert::Get_in(){
	ifstream fin;
	fin.open(path);
	string word;
	while(getline(fin,word)){
		if(word[0]=='+'){
			int size=(int)word.size();
			string newword=word.substr(1,size-1);
			string meaning;
			for(int i=0;i<100;i++){
				string input;
			    getline(fin,input);
			    if(input[0]=='#'){
			    	meaning+=input;
			    }
			    else if(input[0]=='$'){
			    	Word* next=new Word(newword,meaning,0);
			    	collection->push(next);
			    	break;
			    }
			}
		}
	}
}
#endif
