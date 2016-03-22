#include "EndStatement.h"

using namespace std;

EndStatement::EndStatement()
{}
EndStatement::~EndStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void EndStatement::execute(ProgramState * state, ostream &outf)
{
	state -> termin();
	//deallocate all of the things
}