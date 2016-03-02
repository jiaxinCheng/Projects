#include "IfStatement.h"

using namespace std;

IfStatement::IfStatement(std::string variableName, int value, std::string operation, int numlines)
	: m_variableName(variableName), m_value(value), m_oper(operation), linenum(numlines)
{}
IfStatement::~IfStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void IfStatement::execute(ProgramState * state, ostream &outf)
{
	int val = state-> find(m_variableName);
	bool result = false;
	if (m_oper == "="){		//check operater 
		result = (val == m_value);		
	}
	else if (m_oper == "<>"){
		result =  (val != m_value);
	}
	else if (m_oper == ">"){
		result = (m_value < val);
	}
	else if (m_oper == "<"){
		result =  (m_value > val);
	}
	else if (m_oper == ">="){
		result =  (m_value <= val);
	}
	else {
		result = (m_value >= val);
	}
	if (result == true){
		state -> setline(linenum); //if true go to
	}
	else {
		state -> increline();
	}
	// TODO
}
