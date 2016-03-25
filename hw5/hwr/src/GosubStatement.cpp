#include "GosubStatement.h"

using namespace std;

GosubStatement::GosubStatement(int value)
	: m_value(value)
{}
GosubStatement::~GosubStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void GosubStatement::execute(ProgramState * state, ostream &outf)
{
	int linenum = state -> getline();
	
	if (m_value> state -> getStatement()|| m_value < 1){
		state -> setline(-2);
		state -> termin();
		outf << "Illegal jump instruction" << endl;
	}
	else {
		state -> StackPush(linenum + 1);
		state ->setline(m_value);
		state ->altGosub(1);
	}
}