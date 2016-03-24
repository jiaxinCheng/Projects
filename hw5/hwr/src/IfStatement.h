#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class IfStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;
	std::string m_oper;
	int linenum;


public:
	IfStatement(std::string variableName, int value, std::string operation, int numlines);
	virtual ~IfStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
