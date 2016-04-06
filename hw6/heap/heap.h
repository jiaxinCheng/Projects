#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
using namespace std;

template <typename T>
class MinHeap {
  public:
    MinHeap (int d);
       /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

    ~MinHeap ();

    void add (T item, int priority);
         /* adds the item to the heap, with the given priority. */
    const T & peek () const;
         /* returns the element with smallest priority. */
    void remove ();
         /* removes the element with smallest priority. */
    bool isEmpty ();
         /* returns true iff there are no elements on the heap. */
  private:
    //int size;
    void swap(int pos, int pos2);
    void bubbleUp(int pos);
    void trickleDown(int pos);
    int ary;
    vector <T> a;
    vector <int> pri;
};

template <typename T>
MinHeap<T>::MinHeap(int d){
  if ( d < 2){
    throw logic_error("d is not allowed to be less than 2");
  }
  ary =d;
}

template <typename T>
MinHeap<T> :: ~MinHeap(){

}

template <typename T>
bool MinHeap<T>::isEmpty(){ //return empty
  return a.size() ==0;
}

template <typename T>
const T & MinHeap<T>::peek() const{//return the first item
  if (a.size() ==0){
    throw logic_error("calling peek on a empty queue");
  }
  return a[0];
}

template <typename T>
void MinHeap<T>::add(T item,int priority){// add to the back the heap and bubble up
  pri.push_back(priority);
  a.push_back(item);
  bubbleUp(a.size()-1);
}

template <typename T>
void MinHeap<T>::bubbleUp(int pos){// compare the priority and then swap anything that has higher priority
  if (pos >0 && pri[pos] < pri[(pos-1)/ary]){
    swap(pos,(pos-1)/ary);
    bubbleUp((pos-1)/ary);
  }
}

template <typename T>
void MinHeap<T>::remove(){// remove the highest priority item
  if (a.size() ==0){
    throw logic_error("calling remove on a empty queue");
  }
  swap(0,a.size()-1);
  a.pop_back();
  pri.pop_back();
  trickleDown(0);
}

template <typename T>
void MinHeap<T>::trickleDown(int pos){//compare the priority and then swap anything that has lower priority low
  int child = ary* pos +1;
  int temp = child;
  if (child < a.size()){
    for (int i =child; i < temp+ary;++i){
      if (i< a.size() && pri[child] > pri[i]) child =i;
    }
    if (pri[child] < pri[pos]){
      swap(child,pos);
      trickleDown(child);
    }
  }
}

template <typename T>
void MinHeap<T>::swap(int pos, int pos2){// swap function
  T temp = a[pos];
  a[pos] = a[pos2];
  a[pos2] = temp;
  int temp2 = pri[pos];
  pri[pos] = pri[pos2];
  pri[pos2] = temp2;
}