#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <fstream>
#include <string>

using namespace std;

class LexicalAnalyzer
{
	private:
		ifstream *sourceCodeFile;

		struct Data  
		{	
			char cur_char;
			int cur_pos = -1;
			string cur_line;			
		} _data;
	public:
    		LexicalAnalyzer(ifstream*);

    		bool isEOF();
    		char getChar();
    		void readNextLine();
};

#endif
