#include "stackint.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
int compute(string src){
	StackInt stack;
	stringstream ss;
	ss << src;
	const int OPEN_PAREN =-1;
	const int CLOS_PAREN = -2;
	const int RIGH_SHIFT = -3;
	const int LEFT_SHIFT = -4;
	const int MULTI =-5;
	const int PLUS =-6;
	char a;
	while(ss >> a){
		if (a == '<'){
			if(!stack.empty()){// will check wether the stack is empty after every pop
				if (stack.top() > 0 ){// it is impossible for a '<' to have a number in front
					return -1;
				}
				else if (stack.top() == CLOS_PAREN){
					return -1;
				}
				else {
					stack.push(LEFT_SHIFT); // if this is the correct place, then push the shiftleft
				}
			}
			else {
				stack.push(LEFT_SHIFT);	// if stack is empty, we can push the shift right		
			}
		}
		else if (a == '>'){// the following code is basically the same as the block above
			if(!stack.empty()){
				if (stack.top() > 0 ){
					return -1;
				}
				else if (stack.top() == CLOS_PAREN){
					return -1;
				}
				else {
					stack.push(RIGH_SHIFT);
				}
			}
			else {
				stack.push(RIGH_SHIFT);				
			}
		}
		else if (a == '+' ){
			if (stack.empty()){// it is impossible to have a '+' in the front
				return -1;
			}
			else if (stack.top() == LEFT_SHIFT || stack.top() == RIGH_SHIFT || stack.top() == '*'){
				return -1;
			}
			else if (stack.top() == OPEN_PAREN  || stack.top() == '+'){// rule out all the impossible combinations 
				return -1;
			}
			else {				
				stack.push(PLUS);
			} 
		}
		else if (a == '*'){// the following code is basically the same as the block above
			if (stack.empty()){
				return -1;
			}
			else if (stack.top() == LEFT_SHIFT || stack.top() == RIGH_SHIFT || stack.top() == '*'){
				return -1;
			}
			else if (stack.top() == OPEN_PAREN  || stack.top() == '+'){
				return -1;
			}
			else {
				stack.push(MULTI);
			} 
		}
		else if (a == '('){// if there is a open paren, and there is a close before it, reject
			if (!stack.empty()){
				if (stack.top() == CLOS_PAREN){
					return -1;
				}
				else{
					stack.push(OPEN_PAREN);// else we can push it safely 
				}
			}
			else {
				stack.push(OPEN_PAREN);
			}
		}
		else if (a == ')'){ //evaluate the formula in the stack
			if(stack.empty()){
				return -1;
			}
			else if (stack.top() == OPEN_PAREN){
				return -1;
			}
			else if (stack.top() <0){
				return -1;
			}
			int temp2;
			int re = stack.top();
			stack.pop();
			if (stack.empty()){
				return -1;
			}
			while (stack.top() != OPEN_PAREN){
				if (stack.empty()){
					return -1;
				}				
				if (stack.top() == MULTI){//if we see a multi
					stack.pop();
					if (stack.empty()){
						return -1;
					}
					temp2 = stack.top();
					stack.pop();
					if (stack.empty()){
						return -1;
					}
					while(stack.top() == RIGH_SHIFT || stack.top() == LEFT_SHIFT){// while we have the shift left and right, continue times two or half
						if (stack.top() == RIGH_SHIFT){
							temp2 = temp2/2;
							stack.pop();
							if (stack.empty()){
								return -1;
							}
						}
						else{
							temp2 = temp2 *2;
							stack.pop();
							if (stack.empty()){
								return -1;
							}
						}
						if (stack.empty()){//check empty
							return -1;
						}
					}
					if (stack.top() == PLUS){// inside two parenth, if we see a multi first and a plus, reject
						return -1;
					}
					re = re * temp2; //times two of the number together
				}
				if (stack.top() == PLUS){ // this block is the same as above 
					stack.pop();
					if (stack.empty()){
						return -1;
					}
					temp2 = stack.top();
					stack.pop();
					if (stack.empty()){
						return -1;
					}
					while(stack.top() == RIGH_SHIFT || stack.top() == LEFT_SHIFT){
						if (stack.top() == RIGH_SHIFT){
							temp2 = temp2/2;
							stack.pop();
							if (stack.empty()){
								return -1;
							}
						}
						else {
							temp2 = temp2 *2;
							stack.pop();
							if (stack.empty()){
								return -1;
							}
						}
						if (stack.empty()){
							return -1;
						}
					}
					if (stack.top() == MULTI){
						return -1;
					}
					re = re + temp2;
				}
				if (stack.top() == RIGH_SHIFT){ //in the parenth, if we see a right, then times half
					re = re/2;
					stack.pop();
					if (stack.empty()){
						return -1;
					}
				}
				if (stack.top() == LEFT_SHIFT){// if we see a left, times two 
					re = re*2;
					stack.pop();
					if (stack.empty()){
						return -1;
					}
				}
			}
			if (!stack.empty()){
				if (stack.top() == OPEN_PAREN){// pop the open parenth corresponding to the close 
					stack.pop();
				}
			}
			stack.push(re);
		}
		else if (a >= 48 && a <= 57){// if there is a number, then we push as long there is no number before it
			if (stack.empty()){
				stack.push(a-48);
			}
			else if (stack.top() >0){ // if there is a number before the number, times the previous one by 10 and add to number we have
				int topnum =stack.top();
				topnum = 10 *topnum+((int)a-48);
				stack.pop();
				stack.push(topnum);
			}
			else{
				stack.push(a-48);
			}
		}
	}	
	int final =  stack.top();
	stack.pop();
	if (stack.empty() && final > 0){// if there is nothing remaining, return 
		return final;
	}
	else {
		while(!stack.empty()){// if there is somthing remaining, it must be some shifts, finish them and pop
			if (stack.top() == RIGH_SHIFT){
				final = final/2;
				stack.pop();
			}
			else if (stack.top() == LEFT_SHIFT){
				final = final *2;
				stack.pop();
			}
			else {// if what remaining are not parenth, then it is malformed
				return -1;
			}
		}
		return final;
	}
}
int main(int argc, char *argv[]){	
	if (argc !=  2){
		cout << "Provide correct command" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	while (!in.fail()){
		string temp;
		getline(in, temp);
		int result;
		if(!temp.empty()){
			
			result =compute(temp);
			if (result == -1){
				cout << "Malfunction" << endl;
			} 
			else{
				cout << result << endl;
			}
		}
	}		
}

