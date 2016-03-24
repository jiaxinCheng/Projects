#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_multedName;


public:
	MultStatement(std::string variableName, std::string someValue);
	virtual ~MultStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
