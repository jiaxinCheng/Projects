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
	state -> StackPush(linenum + 1);
	state ->setline(m_value);
}