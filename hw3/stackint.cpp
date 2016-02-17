#include "stackint.h"

StackInt::StackInt(){
	//LListInt * a = new LListInt();
	//list = *a;
}

StackInt::~StackInt(){
	//delete &list;
	//list = NULL;
} 

bool StackInt::empty() const{
	return (list.empty()); // can i use a here? 
}

void StackInt::push(const int& val){
	list.insert(0,val);
	return;
}

int const & StackInt::top()const{
	return list.get(0);
}

void StackInt::pop(){
	list.remove(0);
	return;
}


