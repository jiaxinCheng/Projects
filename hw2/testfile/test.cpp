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
  // Insert an item at the tail
  list -> insert(1,4);
  // check if the insert succeed
  if (list -> get(1) == 4 && list -> size() == 2){
    cout << "SUCCESS: Inserting at the tail succeed." << endl;
  }
  else{
    cout << "FAIL: the insert at tail fails." << endl;
  }
  //Insert out of the boundary
  list -> insert(10,6);
  // check if the list is still the same 
  if (list -> size() == 2 && list -> get(1) == 4 && list -> get(0) ==3){
    cout << "SUCCESS: The list is the same when location is out of range." << endl;
  }
  else {
    cout << "FAIL: The list has been changed." << endl;
  }
  // insert at the head while the list is not empty 
  list -> insert(0,1);
  if (list -> size() == 3 && list -> get(0) == 1 && list -> get(1) ==3&& list -> get(2) == 4){
    cout << "SUCCESS: The insert at head works fine ." << endl;
  }
  else {
    cout << "FAIL: The insert fails." << endl;
  }
  //remove out of the boundary 
  list -> remove(4);
  list -> remove(3);
  
  if(list-> size() == 3 && list -> get(1) == 3 && list -> get(2) ==4 && list-> get(0) == 1){
    cout << "SUCCESS: The list is the same when location is out of range." << endl;
  }
  else{
    cout << "FAIL: The list has been changed." << endl;
  }
  //remove the last item
  list -> remove(2);
  if (list -> get(1) == 3 && list -> size() == 2 && list-> get(0) ==1){ 
  cout << "SUCCESS: the last node has been removed." << endl;
  }
  else{
    cout << "FAIL: the removing fails." << endl;
  }
  //insert at middle
  list -> insert (1,7);
  if (list -> get(0) == 1 && list -> size() == 3 && list-> get(1) ==7 && list -> get(2) == 3){ 
  cout << "SUCCESS: the insert at middle succeed." << endl;
  }
  else{
    cout << "FAIL: the inserting fails." << endl;
  }
  //remove the middle item
  list -> remove(1);
  if (list -> get (0) == 1 && list -> size() == 2 && list->get(1) ==3){
    cout << "SUCCESS: the middle node has been removed." << endl;
  }
  else {
    cout << "FAIL: the removing fails." << endl;
  }
  //remove head
  list -> remove(0);
  if (list -> get(0) == 3 && list -> size() ==1){ 
  cout << "SUCCESS: The first item has been removed" << endl;
  }
  else{
    cout << "FAIL: the removing fails ." << endl;
  }
  //remove the only item of the list 
  list -> remove(0);
  if (list -> empty()){ 
  cout << "SUCCESS: The only item has been removed" << endl;
  }
  else{
    cout << "FAIL: the removing fails ." << endl;
  }
  //inserting a negative location 
  list -> insert(-1, 3);
  if (list -> empty()){
    cout << "SUCCESS: the list has not been changed." << endl;
  }
  else{
    cout << "FAIL: The list is not empty." << endl;
  }
}
