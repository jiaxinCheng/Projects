// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <string>
#include <ostream>
#include <vector>
#include <map>
#include <sstream>

class ProgramState
{
public:
	ProgramState(int numLines);
	~ProgramState();
	void increline();//
	void setline(int gotoline);//
	int getline();//
	bool endcheck();//
	void termin();//
	void printall(std::ostream &outf);//
	int find(std::string var);
	void setval(std::string var, int val);
	void StackPush(int line);
	int StackTop();
	bool StackEmpty();
	void setStatement(int val);
	void altGosub(int val);
	int getGosub();
	int getStatement();
	void start();
	std::vector<std::pair<std::string, int> > getValue();
	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.


private:
	int m_numLines;
	int m_numStatement;
	bool end; //to state whether the program is ended
	int gosub;
	std::map<std::string, int> vari;
	StackInt stack;
};

#endif



