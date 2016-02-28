#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "../Statement.h"
#include "../ProgramState.h"


class DivStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_divedName;


public:
	DivStatement(std::string variableName, std::string someValue);
	virtual ~DivStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif