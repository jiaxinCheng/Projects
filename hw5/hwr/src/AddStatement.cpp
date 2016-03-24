#include "AddStatement.h"
#include <sstream>
using namespace std;

AddStatement::AddStatement(std::string variableName, std:: string someValue)
	: m_variableName(variableName), m_addedName(someValue)
{}
AddStatement::~AddStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void AddStatement::execute(ProgramState * state, ostream &outf)
{
	int val = state -> find(m_variableName);
	stringstream ss;
	ss << m_addedName;
	int added;
	if(ss >> added){ //to see whether it's a number
		val += added;
	}
	else {
		added = state -> find(m_addedName);
		val += added;
	}
	state -> setval(m_variableName, val);
	// TODO
	state-> increline();
}