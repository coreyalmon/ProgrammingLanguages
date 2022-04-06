#include <iostream>
#include <fstream>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;
// CODE HAS BEEN EDITED PAST SUBMISSION. IF YOU WANT SUBMISSION CODE, UNZIP ALMONTE_COREY_ASSIGNMENT1.ZIP
// Nothing in this code protects against printing NULL at end (so use submission code) as Assignment1.cpp does not
// protect against printing the null character at the end. (see ./Assignment test.txt > ans.txt)
// This current code is just meant to better reflect how istream does it.
LexicalAnalyzer::LexicalAnalyzer(ifstream *scf)
{
	sourceCodeFile = scf;
	this->readNextLine();
	
}

bool LexicalAnalyzer::isEOF()
{	
	return ((sourceCodeFile->rdstate() & ifstream::eofbit) != 0);
	
}

char LexicalAnalyzer::getChar()
{
	
	if(_data.cur_pos > _data.cur_line.length()-1) 
	{
		_data.cur_line = "";
        	this->readNextLine();
		_data.cur_pos = 0;
	}

	_data.cur_char = _data.cur_line[_data.cur_pos];
	_data.cur_pos+=1;	

	return _data.cur_char;
}

void LexicalAnalyzer::readNextLine()
{
		// If read()/getline() reads past the last byte, the eofbit is triggered and eof() returns true
		if(this->isEOF()) 
			return;
		char line[256];
		sourceCodeFile->getline(line, 256);
		_data.cur_line = _data.cur_line + line + "\n";	
}
