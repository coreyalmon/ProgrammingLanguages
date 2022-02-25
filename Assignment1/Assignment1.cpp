#include <fstream>
#include <iostream>
#include "LexicalAnalyzer.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Delete me before submitting pls" << endl;
  char ch;
  ifstream sourceCodeFile;
  LexicalAnalyzer *la;

  sourceCodeFile.open(argv[1], ifstream::in);
  if  (sourceCodeFile.is_open())
  {
	//sourceCodeFile.seekg(0, sourceCodeFile.end);
	//cout << sourceCodeFile.tellg() << endl;
	//exit(1);
	
	cout << "\n\n\n\n\n\n WEEEEE GOT THIS FAR \n\n\n\n\n";
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
