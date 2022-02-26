#include <iostream>
#include <fstream>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

LexicalAnalyzer::LexicalAnalyzer(ifstream *scf)
{
	sourceCodeFile = scf;
}

bool LexicalAnalyzer::isEOF()
{
	sourceCodeFile->seekg(0, sourceCodeFile->cur);
	int cur = sourceCodeFile->tellg();

	sourceCodeFile->seekg(0, sourceCodeFile->end);
	int len = sourceCodeFile->tellg();

	sourceCodeFile->seekg(cur, sourceCodeFile->beg);

	return cur >= len;
}

char LexicalAnalyzer::getChar()
{
	_data.cur_pos+=1;
	
	if(sourceCodeFile->gcount() == 0) this->readNextLine();
	
	if(_data.cur_pos >  _data.cur_line.length()-1) 
	{
		_data.cur_line = "";
        	this->readNextLine();
		_data.cur_pos = 0;
	}

	_data.cur_char = _data.cur_line[_data.cur_pos];	
	return _data.cur_char;
}

void LexicalAnalyzer::readNextLine()
{	
	char * buff = new char [1];
	while(!this->isEOF())
	{
		sourceCodeFile->read(buff, 1);
		_data.cur_line += buff[0];
		if(buff[0] == '\n') return;	
	}

	delete[] buff;
}
