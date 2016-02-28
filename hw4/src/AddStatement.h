#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "../Statement.h"
#include "../ProgramState.h"


class AddStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_addedName;


public:
	AddStatement(std::string variableName, std::string someValue);
	virtual ~AddStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif