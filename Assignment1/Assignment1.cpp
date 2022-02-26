#include <fstream>
#include <iostream>
#include "LexicalAnalyzer.h"

using namespace std;

int main(int argc, char *argv[])
{
  char ch;
  ifstream sourceCodeFile;
  LexicalAnalyzer *la;

  sourceCodeFile.open(argv[1], ifstream::in);
  if  (sourceCodeFile.is_open())
  {
    la = new LexicalAnalyzer(&sourceCodeFile);
    while (!la->isEOF())
    {   
      ch = la->getChar();
      cout << ch; 
    }
    delete la;
  }
  else 
    printf("ERROR - cannot open input file \n");	
	
  return 0;
}
