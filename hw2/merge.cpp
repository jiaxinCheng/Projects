#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
Node* merge(Node*& first, Node*& second){
	if (first == NULL && second == NULL){
		return NULL;//if the list is empty then return NULL;
	}
	else if (first == NULL && second != NULL){
		Node* second1=second;
		second1->next=merge(first,second->next);
		second = NULL;
		return second1;//if the first list runs out, return the pointer of second list one by one
	}
	else if(first != NULL && second == NULL){
		Node* first1=first;
		first1->next=merge(first->next,second);
		first = NULL;
		return first1;
	}
	else{
		if (first -> value > second -> value){		
			second->next = merge(first, second ->next);	
			Node* second2 = second;
			second = NULL;
			return second2;	// if the first one is greater, then do the merge on the first and the next of second;
		}
		else {
			first->next = merge(first -> next, second);
			Node* first2 = first;
			first = NULL;
			return first2;
		}
	}
		
}


