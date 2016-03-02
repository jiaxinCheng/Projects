// Facile.cpp
#include "src/Statement.h"
#include "src/LetStatement.h"
#include "src/PrintStatement.h"
#include "src/IfStatement.h"
#include "src/EndStatement.h"
#include "src/PrintAllStatement.h"
#include "src/GotoStatement.h"
#include "src/AddStatement.h"
#include "src/SubStatement.h"
#include "src/MultStatement.h"
#include "src/DivStatement.h"
#include "src/ReturnStatement.h"
#include "src/GosubStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		//if(!inf.eof()){
			program.push_back( parseLine( line ) );
		//}		
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	int val;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}
	if (type == "PRINT"){
		ss >> var;
		statement = new PrintStatement(var);
	}
	if (type == "END"|| type == "."){
		statement = new EndStatement();
	}
	if (type == "IF"){
		ss >> var;
		string oper;
		ss >> oper;
		ss >> val;
		string then;
		ss >> then;
		int lnum;
		ss >> lnum;
		statement = new IfStatement(var,val,oper,lnum);
	}
	if (type == "PRINTALL"){
		statement = new PrintAllStatement();
	}

	if (type == "GOTO"){
		ss >> val;
		statement = new GotoStatement(val);
	}

	if (type == "ADD"){
		string something;
		ss >> var;
		ss >> something;
		statement = new AddStatement(var, something);
	}
	if (type == "SUB"){
		string something;
		ss >> var;
		ss >> something;
		statement = new SubStatement(var, something);
	}
	if (type == "MULT"){
		string something;
		ss >> var;
		ss >> something;
		statement = new MultStatement(var, something);
	}
	if (type == "DIV"){
		string something;
		ss >> var;
		ss >> something;
		statement = new DivStatement(var, something);
	}
	
	if (type == "GOSUB"){
		ss >> val;
		statement = new GosubStatement(val);
	}
	
	if(type == "RETURN"){
		statement = new ReturnStatement();
	}
	
	
	// Incomplete;  TODO:  Finish this function!
	//what remaining are the number operations
	
	return statement;
}


void interpretProgram(istream& inf, ostream& outf){

	vector<Statement *> program;
	parseProgram( inf, program );
	ProgramState state(1,false);
	if (program.size() > 1001){
		outf << "Exceeding 1000 lines" << endl;
	}
	else{
		while (state.endcheck() != true){	
			unsigned int i = state.getline();
			if (i > program.size()|| i < 1){
				state.termin();
				outf << "Illegal jump instruction" << endl;
			}
			else{
				program[i]->execute(&state,outf);
			}				
		}
		for (unsigned int j = 0; j < program.size();++j){
			delete program[j];
			program[j] =NULL;
		}
	}
	// Incomplete;  TODO:  Finish this function!
}

