#include "ReturnStatement.h"

using namespace std;

ReturnStatement::ReturnStatement()
{}

ReturnStatement::~ReturnStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	if(state -> StackEmpty()){ //if nothing in stack terminate the program
		state -> termin();
	}
	else {
		int line = state -> StackTop();
		state -> setline(line);
		state -> altGosub(-1);
	}
	
}