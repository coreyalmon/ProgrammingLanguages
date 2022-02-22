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
{//attempts to read past the last positon in the file sets EOF or is it the final byte? 
	sourceCodeFile->seekg(0, ios::cur);
	int current = sourceCodeFile->tellg();
	sourceCodeFile->seekg(0, ios::end);
	int length = sourceCodeFile->tellg();
	if(current != length)
		return false;
	return true;
	
}

char LexicalAnalyzer::getChar()
{
	return 'd';
}

void LexicalAnalyzer::readNextLine()
{
	return;
}
