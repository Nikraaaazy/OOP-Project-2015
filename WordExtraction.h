#ifndef WORD_EXTRACTION_H
#define WORD_EXTRACTION_H

#include <iostream>
#include <string>

using namespace std;

class WordExtraction
{
private:
	string inputPath;
public:
	WordExtraction(string path);
	void extract();
};

#endif 