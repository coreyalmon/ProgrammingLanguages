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
			char curr_char;
			int pos = -1;
			string curr_line;			
		} _data;
	public:
    		LexicalAnalyzer(ifstream*);

    		bool isEOF();
    		char getChar();
    		void readNextLine();
};

#endif
