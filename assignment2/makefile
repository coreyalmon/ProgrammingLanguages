#Makefile for Assignment1

Assignment2: Assignment2.o LexicalAnalyzer.o Token.o
	g++ -o Assignment2 Assignment2.o LexicalAnalyzer.o Token.o
	make move

Assignment2.o: Assignment2.cpp LexicalAnalyzer.h
	g++ -g -D_GLIBCXX_DEBUG -c Assignment2.cpp 

LexicalAnalyzer.o: LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -D_GLIBCXX_DEBUG -c LexicalAnalyzer.cpp

Token.o: Token.cpp Token.h TokenCodes.h
	g++ -g -D_GLIBCXX_DEBUG -c Token.cpp

move:
	mkdir -p Objectfiles
	mv *.o Objectfiles 

clean:
	rm -r  Objectfiles
	rm .*.swp 
	rm Assignment1
