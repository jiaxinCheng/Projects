#include "MultStatement.h"
#include <sstream>
using namespace std;

MultStatement::MultStatement(std::string variableName, std:: string someValue)
	: m_variableName(variableName), m_multedName(someValue)
{}
MultStatement::~MultStatement(){
}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void MultStatement::execute(ProgramState * state, ostream &outf)
{
	int val = state -> find(m_variableName);
	stringstream ss;
	ss << m_multedName;
	int multed;
	if(ss >> multed){
		val *= multed;
	}
	else {
		multed = state -> find(m_multedName);
		val *= multed;
	}
	state -> setval(m_variableName, val);
	// TODO
	state-> increline();
}