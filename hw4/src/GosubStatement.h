#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "../Statement.h"
#include "../ProgramState.h"

class GosubStatement: public Statement
{
private:
	int m_value;
	
public:
	GosubStatement(int value);
	virtual ~GosubStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif