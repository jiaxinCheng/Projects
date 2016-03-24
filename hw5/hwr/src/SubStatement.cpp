#include "SubStatement.h"
#include <sstream>
using namespace std;

SubStatement::SubStatement(std::string variableName, std:: string someValue)
	: m_variableName(variableName), m_subedName(someValue)
{}

SubStatement::~SubStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void SubStatement::execute(ProgramState * state, ostream &outf)
{
	int val = state -> find(m_variableName);
	stringstream ss;
	ss << m_subedName;
	int subed;
	if(ss >> subed){
		val -= subed;
	}
	else {
		subed = state -> find(m_subedName);
		val -= subed;
	}
	state -> setval(m_variableName, val);
	// TODO
	state-> increline();
}