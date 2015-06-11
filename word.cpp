#include "Word.h"

Word::Word()
{

}

Word::Word(string word, string all, int wordLevel)
{
	this -> word = word;
	this -> all = all;
	this -> wordLevel = wordLevel;
}

Word::Word(Word& word)
{
	this -> word = word.word;
	this -> all = word.all;
	this -> wordLevel = word.wordLevel;
}

string Word::getWord()
{
	return word;
}

string Word::getAll()
{
	return all;
}

int Word::getWordLevel()
{
	return wordLevel;
}

void Word::setWordLevel(int level)
{
	wordLevel = level;
}

bool Word::operator==(Word &word)
{
	return this -> word == word.word;
}