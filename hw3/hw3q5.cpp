#include "stackint.cpp"
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
			if(!stack.empty()){
				if (stack.top() > 0 ){
					return -1;
				}
				else if (stack.top() == CLOS_PAREN){
					return -1;
				}
				else {
					stack.push(LEFT_SHIFT);
				}
			}
			else {
				stack.push(LEFT_SHIFT);				
			}
		}
		else if (a == '>'){
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
				stack.push(PLUS);
			} 
		}
		else if (a == '*'){
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
		else if (a == '('){
			if (!stack.empty()){
				if (stack.top() == CLOS_PAREN){
					return -1;
				}
				else{
					stack.push(OPEN_PAREN);
				}
			}
			else {
				stack.push(OPEN_PAREN);
			}
		}
		else if (a == ')'){
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
				if (stack.top() == MULTI){
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
						else{
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
					if (stack.top() == PLUS){
						return -1;
					}
					re = re * temp2;
				}
				if (stack.top() == PLUS){
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
				if (stack.top() == RIGH_SHIFT){
					re = re/2;
					stack.pop();
					if (stack.empty()){
						return -1;
					}
				}
				if (stack.top() == LEFT_SHIFT){
					re = re*2;
					stack.pop();
					if (stack.empty()){
						return -1;
					}
				}
			}
			if (!stack.empty()){
				if (stack.top() == OPEN_PAREN){
					stack.pop();
				}
			}
			stack.push(re);
		}
		else if (a >= 48 && a <= 57){
			if (stack.empty()){
				stack.push(a-48);
			}
			else if (stack.top() >0){
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
	if (stack.empty() && final > 0){
		return final;
	}
	else {
		while(!stack.empty()){
			if (stack.top() == RIGH_SHIFT){
				final = final/2;
				stack.pop();
			}
			else if (stack.top() == LEFT_SHIFT){
				final = final *2;
				stack.pop();
			}
			else {
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
		if(!in.fail()){
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

