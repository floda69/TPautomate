main : automate.o Etat.o lexer.o main.o symbole.o
	g++ -o main automate.o Etat.o lexer.o main.o symbole.o

automate.o : automate.cpp automate.h
	g++ -c automate.cpp

Etat.o : Etat.cpp Etat.h
	g++ -c Etat.cpp

lexer.o : lexer.cpp lexer.h
	g++ -c lexer.cpp

main.o : main.cpp	
	g++ -c main.cpp

symbole.o : symbole.cpp symbole.h
	g++ -c symbole.cpp

clean :
	rm -f main.exe *.o