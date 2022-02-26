#Makefile for Assignment1

Assignment1: Assignment1.o LexicalAnalyzer.o
	g++ -o Assignment1 Assignment1.o LexicalAnalyzer.o
	make move

Assignment1.o: Assignment1.cpp LexicalAnalyzer.h
	g++ -g -D_GLIBCXX_DEBUG -c Assignment1.cpp 

LexicalAnalyzer.o: LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -D_GLIBCXX_DEBUG -c LexicalAnalyzer.cpp

move:
	mkdir -p Objectfiles
	mv *.o Objectfiles 

clean:
	rm -r  Objectfiles 
	rm Assignment1
