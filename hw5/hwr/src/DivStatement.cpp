#include "DivStatement.h"
#include <sstream>
using namespace std;

DivStatement::DivStatement(std::string variableName, std:: string someValue)
	: m_variableName(variableName), m_divedName(someValue)
{}
DivStatement::~DivStatement(){}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void DivStatement::execute(ProgramState * state, ostream &outf)
{
	int val = state -> find(m_variableName);
	stringstream ss;
	ss << m_divedName;
	int dived;
	if(ss >> dived){
		if (dived == 0){
			state -> setline(-1);
			state -> termin();
			outf << "Divide by zero exception" << endl;
		}
		else {
			val /= dived;
			state-> increline();
		}
	}
	else {
		dived = state -> find(m_divedName);
		if (dived == 0){
			state -> setline(-1);
			state -> termin();
			outf << "Divide by zero exception" << endl;
		}
		else{
			val /= dived;
			state-> increline();
		}
		
	}
	state -> setval(m_variableName, val);
	// TODO
	
}