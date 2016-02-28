// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}

PrintStatement::~PrintStatement(){
}

void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << state->find(m_variableName) <<std::endl;
	state-> increline();
}


