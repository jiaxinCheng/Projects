#include "GotoStatement.h"
using namespace std;

GotoStatement::GotoStatement(int value): m_value(value)
{}
GotoStatement::~GotoStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void GotoStatement::execute(ProgramState * state, ostream &outf)
{
	state -> setline(m_value);

}