#ifndef WORDTEST_H
#define WORDTEST_H
#include "Word.h"
#include "WordCollection.h"
#include<cstdlib>
using namespace std;
class WordTest{
	public:
		WordTest(){
			fac=new WordCollectionFactory;
			collections=NULL;
			WordNumber=50;
		}
		WordTest(int num){
			fac=new WordCollectionFactory;
			WordNumber=num;
			collections=NULL;
		}
		WordTest(istream& os){
			os>>WordNumber;
			fac=new WordCollectionFactory;
			collections=NULL;
		}
		void Test(){
			collections=fac->create(WordNumber);
			Word* s=new Word;
			while(s){
				s=collections->next();
				if(!s)  break;
				string word=s->getWord();
				cout<<word<<endl;
				char* input=new char[10];
				cin>>input;
				if(input[0]=='Y'){
					int level=s->getWordLevel();
					s->setWordLevel(++level);
					string mean=s->getAll();
					cout<<mean<<endl;
					system("cls");
				}
				else if(input[0]=='N'){
					int level=s->getWordLevel();
					if(s>0){
						s->setWordLevel(--level);
					}
					string mean=s->getAll();
					cout<<mean<<endl;
					collections->push(s);
					system("cls");
				}
			}
			cout<<"背诵任务完成。Good！！！"<<endl;
		}
	private:
		WordCollectionFactory* fac;
		WordCollection* collections;
		int WordNumber;
};
#endif
