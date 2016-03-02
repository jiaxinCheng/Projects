#include "ProgramState.h"

ProgramState::ProgramState(int numlines, bool endc){
	m_numLines = numlines;
	end = endc;
}
ProgramState::~ProgramState(){

}
void ProgramState::increline(){
	m_numLines++;
}
void ProgramState::setline(int line){
	m_numLines = line;
}

int ProgramState::find(std::string var){
	int num = 0;
	bool find = false;
	std::map<std::string, int>::iterator it;
	for (it = vari.begin(); it != vari.end(); ++it){
		if(it -> first == var){
			num = it -> second;
			find = true;
		}
	}
	if (!find){
		setval(var,0);
	}
	return num;
}
void ProgramState::printall(std::ostream &outf){
	std::map<std::string, int>::iterator it;
	for (it = vari.begin(); it != vari.end(); ++it){
		outf << it -> first << " "<< it -> second << std::endl;
	}
}
void ProgramState::setval(std::string var,int val){
	vari[var] = val;
}
int ProgramState::getline(){
	return m_numLines;
}
void ProgramState::termin(){
	end = true;
}
bool ProgramState::endcheck(){
	return end;
}
void ProgramState::StackPush(int line){
	stack.push(line);
}
int ProgramState::StackTop(){
	int a = stack.top();
	stack.pop();
	return a;
}
bool ProgramState::StackEmpty(){
	return stack.empty();
}

