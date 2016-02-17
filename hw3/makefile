# Let's declare some variables
CC       = g++
CPPFLAGS = -Wall -g
BIN_DIR  = bin
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

# $^ is an auto variable that means "all dependencies",
#   which are test.cpp and $(BIN_DIR)/fib.o in this case
# IMPORTANT: $(GTEST_LL) needs to come *after* the source files
$(BIN_DIR)/llistintTest: test.cpp $(BIN_DIR)/llistint.o
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

.PHONY: tests

hw3q5: bin/llistint.o hw3q5.cpp bin/.dirstamp bin/stackint.o
	g++ -Wall -g bin/stackint.o bin/llistint.o hw3q5.cpp -o hw3q5

tests: $(BIN_DIR)/llistintTest bin/.dirstamp
	-@$(BIN_DIR)/llistintTest
	-@echo "--- All Tested!---"



bin/llistint.o: llistint.h llistint.cpp bin/.dirstamp
	g++ -Wall -g -c llistint.cpp -o bin/llistint.o

bin/stackint.o: stackint.h stackint.cpp bin/llistint.o bin/.dirstamp
	g++ -Wall -g -c stackint.cpp -o bin/stackint.o


bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp

cleanall: 
	rm bin/stackint.o hw3q5 bin/llistint.o bin/llistintTest
	rm -rf bin

cleantests:
	rm bin/llistint.o bin/llistintTest

cleanhw:
	rm bin/llistint.o bin/stackint.o hw3q5