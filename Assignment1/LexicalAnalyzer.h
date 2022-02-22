#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <fstream>
#include <string>

using namespace std;

class LexicalAnalyzer
{
	private:
		ifstream *sourceCodeFile;
		typedef struct Data  
		{	
			char last_char;
			int offset;
			string next_line;			
		} _data;
	public:
    		LexicalAnalyzer(ifstream*);

    		bool isEOF();
    		char getChar();
    		void readNextLine();
};

#endif
