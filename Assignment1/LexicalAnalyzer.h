#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <fstream>
#include <string>

using namespace std;

class LexicalAnalyzer
{
  private:
    ifstream *sourceCodeFile;


  public:
    LexicalAnalyzer(ifstream*);

    bool isEOF();
    char getChar();
    void readNextLine();
};

#endif
