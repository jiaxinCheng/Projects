#include "ProgramState.h"
using namespace std;
ProgramState::ProgramState(int numlines){
	m_numLines = numlines;
	end = false;
	m_numStatement = 0;
	gosub = false;
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
	for (it = vari.begin(); it != vari.end(); ++it){ //find whether the varible exist
		if(it -> first == var){
			num = it -> second;
			find = true;
		}
	}
	if (!find){ //not, set new varible to 0
		setval(var,0);
	}
	return num;
}
void ProgramState::printall(std::ostream &outf){ //iterate the map
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
bool ProgramState::StackEmpty(){ //check whether the stack is empty
	return stack.empty();
}
void ProgramState::setStatement(int val){
	m_numStatement = val;
}
int ProgramState::getStatement(){
	return m_numStatement;
}
vector<pair<string, int> > ProgramState::getValue(){
	map<string,int>:: iterator it;
	vector<std::pair<string,int> > a;
	for(it = vari.begin(); it != vari.end();++it){
		a.push_back(std::make_pair(it -> first, it ->second));
	}
	return a;
}

void ProgramState::setGosub(bool val){
	gosub = val;
}
bool ProgramState::getGosub(){
	return gosub;
}