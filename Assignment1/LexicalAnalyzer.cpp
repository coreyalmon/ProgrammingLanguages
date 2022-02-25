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
	return sourceCodeFile->eof();
	
}

char LexicalAnalyzer::getChar()
{
	_data.pos+=1;
	
	cout << "1\n";
	if(sourceCodeFile->gcount() == 0)
		this->readNextLine();
	
	if(_data.pos > (sizeof(_data.curr_line)/sizeof(string))) 
	{
        	this->readNextLine();
		_data.pos = 0;
	}
	_data.curr_char = _data.curr_line[_data.pos];	
	return _data.curr_char;
}

// read 128 bytes (we reading in blocks)
// then
void LexicalAnalyzer::readNextLine()
{
	cout << "2\n";
	char * buff = new char [1];
	while(!this->isEOF())
	{
	cout << "3\n";
		sourceCodeFile->read(buff, 1);
		_data.curr_line += buff[0];
		if(buff[0] == '\n')
			return;	
	}
}

// run a file only using getchar (printing results) to see if it iterates through whole file
