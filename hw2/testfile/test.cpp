#include "../llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list->insert(0, 3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }
  list -> insert(1,4);
  if (list -> get(1) == 4){
    cout << "SUCCESS: Inserting the right number." << endl;
  }
  else{
    cout << "FAIL: The number is wrong." << endl;
  }
  list -> insert(10,4);
  if (list -> size() == 2 && list -> get(1) == 4 && list -> get(0) ==3){
    cout << "SUCCESS: The list is the same when location is out of range." << endl;
  }
  else {
    cout << "FAIL: The list has been changed." << endl;
  }
  //list -> insert(3,6);
  list -> remove(3);
  list -> remove(2);
  if(list-> size() == 2 && list -> get(1) == 4 && list -> get(0) ==3){
    cout << "SUCCESS: The list is the same when location is out of range." << endl;
  }
  else{
    cout << "FAIL: The list has been changed." << endl;
  }
  
  list -> remove(1);
  if (list -> get(0) == 3 && list -> size() == 1){ 
  cout << "SUCCESS: the last node has been removed." << endl;
  }
  else{
    cout << "FAIL: the removing fails." << endl;
  }
  list -> insert (1,7);
  list -> remove(0);
  if (list -> get (0) == 7 && list -> size() == 1){
    cout << "SUCCESS: the first node has been removed." << endl;
  }
  else {
    cout << "FAIL: the removing fails." << endl;
  }
  list -> remove(0);
  if (list->empty()){ 
  cout << "SUCCESS: The list has been emptied" << endl;
  }
  else{
    cout << "FAIL: The list is not emptied." << endl;
  }
  list -> insert(-1, 3);
  if (list -> empty()){
    cout << "SUCCESS: The list has been empty." << endl;
  }
  else{
    cout << "FAIL: The list is not empty." << endl;
  }
  
  

}