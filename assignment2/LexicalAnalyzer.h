#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <fstream>
#include <string>
#include "Token.h"
#include <unordered_map>
#include <vector>

using namespace std;

class LexicalAnalyzer
{
	private:
		ifstream *sourceCodeFile;

		struct Data  
		{	
			char curChar;
			int curPos=-1;
			string curLine;			
		} data;

        const static std::unordered_map<std::string, TokenCodes> tokenMap;    
        const static std::vector<std::string> keywords;
        const static std::vector<std::string> symSubs;

    	bool isEOF();
    	void getChar();
    	void readNextLine(); 

        void skipWhiteSpace();	
        bool isLetter(char ch);   
        bool isNumber(char ch);
        bool isSymbol(char ch);
        bool isKeyword(std::string lexeme);
        bool isSymSub(std::string lexeme);    

    public:
        LexicalAnalyzer(ifstream*);
        Token* getNextToken();
};

#endif
