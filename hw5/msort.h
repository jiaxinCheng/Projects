#include <vector>
#include <iostream>
using namespace std;
template <class T, class Comparator>
void mergeSort (vector<T>& myArray, Comparator comp){
  int a = 0;
  int b = myArray.size()-1;
  mergeSorthelper(myArray,comp, a, b);
}

template <class T,class Comparator>
void mergeSorthelper(vector<T>& array, Comparator comp, int l, int r){
  if (l < r){
  	int m =  (l+r)/2;
  	mergeSorthelper(array, comp,l,m);
  	mergeSorthelper(array, comp, m+1, r);
  	merge(array, comp, l,r,m);
  }
}

template <class T, class Comparator>
void merge(vector<T>& array, Comparator comp, int l, int r, int m){
  int i =, j = m+1, k =0;
  vector<T> temp;
  while(i < =m || j <= r){
  	if(i <= m && (j >r || comp(array[i], array[j]))){
  		temp[k] = array[i];
  		++i;
  		++k;
  	}
  	else{
			temp[k] = array[j];
  		++j;
  		++k;
		}
  	for(k=0; k<r+1-l;++k){
  		array[k+1] = temp[k];
		}
	}
}