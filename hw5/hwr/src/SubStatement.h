#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class SubStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_subedName;


public:
	SubStatement(std::string variableName, std::string someValue);
	virtual ~SubStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
