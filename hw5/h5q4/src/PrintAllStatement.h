#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include "../ProgramState.h"

class PrintAllStatement: public Statement
{

public:
	PrintAllStatement();
	virtual ~PrintAllStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif