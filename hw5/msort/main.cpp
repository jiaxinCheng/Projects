#include <iostream>
#include "msort.h"
#include <string>

using namespace std;

int main(){
	vector <string> a;
	a.push_back("abc");
	a.push_back("bac");
	a.push_back("fight on");
	a.push_back("Trojan");
	a.push_back("cote");
	StringCom coma;
	mergeSort(a,coma);
	for (unsigned int i = 0; i < a.size();++i){
		cout << a[i] << endl;
	}
	cout << endl;
	vector<pair<string, int> >b;
	b.push_back(make_pair("cote",3));
	b.push_back(make_pair("fight on", 4));
	b.push_back(make_pair("Trojan",134));
	b.push_back(make_pair("abc",222));
	b.push_back(make_pair("bac",100000));
	PairCom comb;
	mergeSort(b,comb);
	for (unsigned int i = 0; i < b.size();++i){
		cout << b[i].first <<" " <<b[i].second << endl;
	}
	cout << endl;
	PairCom1 comc;
	mergeSort(b,comc);
	for (unsigned int i = 0; i < b.size();++i){
		cout << b[i].first <<" " <<b[i].second << endl;
	}
}