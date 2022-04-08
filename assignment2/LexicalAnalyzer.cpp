#include <iostream>
#include <fstream>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

const std::unordered_map<std::string, TokenCodes> LexicalAnalyzer::tokenMap  
{
        {"+", static_cast<TokenCodes>(0)},
        {"-", static_cast<TokenCodes>(1)},
        {"*", static_cast<TokenCodes>(2)},
        {"/", static_cast<TokenCodes>(3)},
        {"=", static_cast<TokenCodes>(4)},
        {"(", static_cast<TokenCodes>(5)},
        {")", static_cast<TokenCodes>(6)},
        {".", static_cast<TokenCodes>(7)},
        {",", static_cast<TokenCodes>(8)},
        {";", static_cast<TokenCodes>(9)},
        {":", static_cast<TokenCodes>(10)},
        {":=", static_cast<TokenCodes>(11)},
        {"<", static_cast<TokenCodes>(12)},
        {"<=", static_cast<TokenCodes>(13)},
        {"<>", static_cast<TokenCodes>(14)},
        {">", static_cast<TokenCodes>(15)},
        {">=", static_cast<TokenCodes>(16)},
        {"and", static_cast<TokenCodes>(17)},
        {"begin", static_cast<TokenCodes>(18)},
        {"boolean", static_cast<TokenCodes>(19)},
        {"div", static_cast<TokenCodes>(20)},
        {"do", static_cast<TokenCodes>(21)},
        {"downto", static_cast<TokenCodes>(22)},
        {"else", static_cast<TokenCodes>(23)},
        {"end", static_cast<TokenCodes>(24)},
        {"false", static_cast<TokenCodes>(25)},
        {"for", static_cast<TokenCodes>(26)},
        {"if", static_cast<TokenCodes>(27)},
        {"integer", static_cast<TokenCodes>(28)},
        {"mod", static_cast<TokenCodes>(29)},
        {"not", static_cast<TokenCodes>(30)},
        {"or", static_cast<TokenCodes>(31)},
        {"program", static_cast<TokenCodes>(32)},
        {"read", static_cast<TokenCodes>(33)},
        {"readln", static_cast<TokenCodes>(34)},
        {"real", static_cast<TokenCodes>(35)},
        {"repeat", static_cast<TokenCodes>(36)},
        {"then", static_cast<TokenCodes>(37)},
        {"to", static_cast<TokenCodes>(38)},
        {"true", static_cast<TokenCodes>(39)},
        {"until", static_cast<TokenCodes>(40)},
        {"var", static_cast<TokenCodes>(41)},
        {"while", static_cast<TokenCodes>(42)},
        {"write", static_cast<TokenCodes>(43)},
        {"writeln", static_cast<TokenCodes>(44)},
        {"identifier", static_cast<TokenCodes>(45)},
        {"numeric literal", static_cast<TokenCodes>(46)},
        {"end of input", static_cast<TokenCodes>(47)},
        {"not a lexeme", static_cast<TokenCodes>(48)}
};

const std::vector<std::string> LexicalAnalyzer::keywords 
{
    "and", "begin", "boolean", "div", "do", 
    "downto", "else", "end", "false", "for",
    "if", "integer", "mod", "not", "or",
    "program", "read", "readln", "real", "repeat",
    "then", "to", "true", "until", "var",
    "while", "write", "writeln"
};

const std::vector<std::string> LexicalAnalyzer::symSubs 
{
    "+", "-", "*", "/", "=",
    "(", ")", ".", ",", ";",
    ":", ":=", "<", "<=", "<>",
    ">", ">="
};

LexicalAnalyzer::LexicalAnalyzer(ifstream *scf)
{
	sourceCodeFile = scf;
    getChar();
}

bool LexicalAnalyzer::isEOF()
{
    return ((sourceCodeFile->rdstate() & ifstream::eofbit) != 0);
}

void LexicalAnalyzer::getChar()
{
	data.curPos+=1;
	
	if(sourceCodeFile->gcount() == 0) this->readNextLine();
	
	if(data.curPos >  data.curLine.length()-1) 
	{
		data.curLine = "";
        	this->readNextLine();
		data.curPos = 0;
	}

	data.curChar = data.curLine[data.curPos];	
}

void LexicalAnalyzer::readNextLine()
{	
	char * buff = new char [1];
	while(!this->isEOF())
	{
		sourceCodeFile->read(buff, 1);
		data.curLine += buff[0];
		if(buff[0] == '\n') return;	
	}

	delete[] buff;
}

void LexicalAnalyzer::skipWhiteSpace()
{
    while(data.curChar==' ' || data.curChar=='\n')
        getChar();
}

bool LexicalAnalyzer::isLetter(char ch)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(char letter : alphabet) 
        if(ch == letter)
            return true;

    return false; 
}

bool LexicalAnalyzer::isNumber(char ch)
{
    std::string numberList = "0123456789";
    for(char num : numberList)
        if(ch == num)
            return true;
    
    return false;
}

bool LexicalAnalyzer::isSymbol(char ch)
{
    std::string symbols = "+-*/=().,;:<>";
    for(char sym : symbols)
        if(ch == sym)
            return true;

    return false;
}

bool LexicalAnalyzer::isKeyword(std::string lexeme)
{
    for(std::string keyword : keywords)
        if(lexeme == keyword)
            return true;

    return false;
}

bool LexicalAnalyzer::isSymSub(std::string lexeme)
{
    for(std::string sym : symSubs)
        if(lexeme == sym)
            return true;

    return false;
}

Token * LexicalAnalyzer::getNextToken()
{   
    skipWhiteSpace();
    if(isEOF())
        return new Token(tokenMap.at("end of input"), "end of input");

    std::string lexeme = "";
    if(isLetter(data.curChar))
    {
        while(isLetter(data.curChar) || isNumber(data.curChar))
        {   
            lexeme += data.curChar;
            getChar();
        }
            if(isKeyword(lexeme))
                return new Token(tokenMap.at(lexeme), lexeme);
            else 
                return new Token(tokenMap.at("identifier"), lexeme);
    }
    if(isSymbol(data.curChar))
    {
        while(isSymbol(data.curChar))
        {
            lexeme  += data.curChar;
            getChar();
        }
        if(isSymSub(lexeme))
            return new Token(tokenMap.at(lexeme), lexeme);
        else
        {
            data.curPos -= 1;
            while(!isSymSub(lexeme))
            {
                lexeme.pop_back(); 
                data.curPos -= 1;
            }
                return new Token(tokenMap.at(lexeme), lexeme); 
        }
    }
    if(isNumber(data.curChar)) 
    {
        while(isNumber(data.curChar) || data.curChar == '.')
        {
            lexeme += data.curChar;
            getChar();
        }
            return new Token(tokenMap.at("numeric literal"), lexeme);
    }
        lexeme+=data.curChar;
        getChar();
        return new Token(tokenMap.at("not a lexeme"), lexeme);
}
