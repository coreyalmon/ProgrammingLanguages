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
	int curr = sourceCodeFile->tellg();

	sourceCodeFile->seekg(0, sourceCodeFile->end);
	int len = sourceCodeFile->tellg();

	sourceCodeFile->seekg(curr, sourceCodeFile->beg);

	return curr == len;
}


char LexicalAnalyzer::getChar()
{
	_data.pos+=1;
	
	//cout << "gcount is: " << sourceCodeFile->gcount() << endl;	
	if(sourceCodeFile->gcount() == 0) {
		this->readNextLine();
	}
	
	if(_data.pos >  _data.curr_line.length()-1) 
	{
		_data.curr_line = "";
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
	
	char * buff = new char [1];
	while(!this->isEOF())
	{
		sourceCodeFile->read(buff, 1);
		_data.curr_line += buff[0];
		if(buff[0] == '\n')
			return;	
	}
}
// run a file only using getchar (printing results) to see if it iterates through whole file
