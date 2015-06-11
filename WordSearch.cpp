//#include "  "
//#include "  "
//#include "  "
#include "WordSearch.h"

void wordSearch::getMaxnum()
{
	Maxnum=x;
}

void wordSearch::getTargetWord(string w)
{
	TargetWord=w;
}

void wordSearch::binarySearch()
{
	//do something
	int l=1,r=Maxnum;
	int m=(l+r)/2;
	bool found=false;
	while (r-l>10)
	{
		if (word[m].getWord()==TargetWord) 
		{
			found=true;
			break;
		}
		if (word[m].getWord()>TargetWord)
			r=m-1;
		if (word[m].getWord()<TargetWord)
			l=m+1;
		m=(l+r)/2;
	}
	if (!found)
		for (int i=l;i<=r;i++)
			if (word[i].getWord()==TargetWord)
			{
				m=i;
				found=true;
				break;
			}
	if (found) 
		cout<<word[m].getAll()<<endl;
	else
		cout<<"Cannot find this word!!!"<<endl;
	//string Word::getWord();
	//string Word::getAll();
	//Word word[Maxnum];
}
