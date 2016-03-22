#include "PrintAllStatement.h"
using namespace std;

PrintAllStatement::PrintAllStatement()
{}
PrintAllStatement::~PrintAllStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void PrintAllStatement::execute(ProgramState * state, ostream &outf)
{
	state -> printall(outf);
	state -> increline();
}