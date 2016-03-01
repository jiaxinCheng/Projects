S = src

all: bin/LetStatement.o bin/stackint.o bin/ReturnStatement.o bin/GosubStatement.o bin/llistint.o bin/AddStatement.o bin/SubStatement.o bin/DivStatement.o bin/MultStatement.o bin/PrintStatement.o bin/ProgramState.o Facile bin/EndStatement.o bin/IfStatement.o bin/PrintAllStatement.o bin/GotoStatement.o

bin/llistint.o: llistint.h llistint.cpp bin/.dirstamp
	g++ -g -Wall -c llistint.cpp -o bin/llistint.o

bin/LetStatement.o: $(S)/LetStatement.h $(S)/LetStatement.cpp $(S)/Statement.h bin/.dirstamp
	g++ -g -Wall -c $(S)/LetStatement.cpp -o bin/LetStatement.o

bin/PrintStatement.o: $(S)/PrintStatement.h $(S)/PrintStatement.cpp $(S)/Statement.h bin/.dirstamp
	g++ -g -Wall -c $(S)/PrintStatement.cpp -o bin/PrintStatement.o

bin/ProgramState.o: ProgramState.h ProgramState.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c ProgramState.cpp -o bin/ProgramState.o

bin/stackint.o: stackint.h stackint.cpp bin/llistint.o bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c stackint.cpp -o bin/stackint.o

bin/EndStatement.o: $(S)/EndStatement.h $(S)/EndStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/EndStatement.cpp -o bin/EndStatement.o

bin/ReturnStatement.o: $(S)/ReturnStatement.h $(S)/ReturnStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/ReturnStatement.cpp -o bin/ReturnStatement.o

bin/IfStatement.o: $(S)/IfStatement.h $(S)/IfStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/IfStatement.cpp -o bin/IfStatement.o

bin/PrintAllStatement.o: $(S)/PrintAllStatement.h $(S)/PrintAllStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/PrintAllStatement.cpp -o bin/PrintAllStatement.o

bin/GotoStatement.o: $(S)/GotoStatement.h $(S)/GotoStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/GotoStatement.cpp -o bin/GotoStatement.o

bin/AddStatement.o: $(S)/AddStatement.h $(S)/AddStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/AddStatement.cpp -o bin/AddStatement.o

bin/MultStatement.o: $(S)/MultStatement.h $(S)/MultStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/MultStatement.cpp -o bin/MultStatement.o

bin/SubStatement.o: $(S)/SubStatement.h $(S)/SubStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/SubStatement.cpp -o bin/SubStatement.o

bin/DivStatement.o: $(S)/DivStatement.h $(S)/DivStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/DivStatement.cpp -o bin/DivStatement.o

bin/GosubStatement.o: $(S)/GosubStatement.h $(S)/GosubStatement.cpp bin/.dirstamp $(S)/Statement.h
	g++ -g -Wall -c $(S)/GosubStatement.cpp -o bin/GosubStatement.o

Facile: Facile.cpp bin/LetStatement.o bin/GosubStatement.o bin/ReturnStatement.o bin/MultStatement.o bin/llistint.o bin/stackint.o bin/DivStatement.o bin/PrintStatement.o bin/ProgramState.o bin/SubStatement.o bin/EndStatement.o bin/IfStatement.o bin/PrintAllStatement.o bin/GotoStatement.o bin/AddStatement.o
	g++ -g -Wall $^ -o Facile

bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp

clean: 
	rm bin/LetStatement.o bin/stackint.o bin/ReturnStatement.o bin/GosubStatement.o bin/llistint.o bin/AddStatement.o bin/SubStatement.o bin/DivStatement.o bin/MultStatement.o bin/PrintStatement.o bin/ProgramState.o Facile bin/EndStatement.o bin/IfStatement.o bin/PrintAllStatement.o bin/GotoStatement.o
	rm -rf bin