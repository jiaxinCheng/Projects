#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{ 
  Item* node = new Item;
  node -> val = val;
  if (empty() && loc ==0){
      head_ = node;
      tail_ = node;
      node ->prev = NULL;
      node-> next = NULL;
      size_++;
    }
  else if (loc ==0){
    Item* head1 = head_;
    node -> next = head1;
    head_ = node;
    head1 -> prev = node;
    node -> prev = NULL;
    size_++;
  }
  else if (loc == size_){
    Item* tail1 = tail_;
    node-> next = NULL;
    node -> prev = tail1;
    tail_ = node;
    tail1-> next = node;
    size_++;
  } 
  else if (loc > 0 && loc < size_){
    Item* curr = getNodeAt(loc); 
    Item* befo = curr -> prev;  
    node -> next = curr;
    node -> prev = befo;
    curr -> prev = node;
    curr -> prev -> next = node;
    size_++;

  }
  else {
    return;
  }
  return;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  if (empty()){
    return;
  }
  else if (size_ == 1 && loc == 0){
    clear();
  }
  else if (loc == 0){
    Item* curr = getNodeAt(loc);
    head_ = curr -> next;
    curr -> next -> prev = NULL;
    delete curr;
    size_ --;
  }
  else if (loc == size_-1){
    Item* curr = getNodeAt(loc);
    tail_ = curr -> prev;
    curr ->prev -> next = NULL;
    delete curr;
    size_--;
  }
  else if (loc >0 && loc < size_){
    Item* curr = getNodeAt(loc);
    curr ->prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    delete curr;
    size_--;
  }
  else {
    return;
  }
  return;
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item* temp = head_;
  for (int i = 0; i < loc; i++){
    temp = temp -> next;
  }
  return temp;

}