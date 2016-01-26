#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;
void reverse(stringstream &infile,int num, int count){
	string out;
	
	if (count == num){
		
		return;
	}
	else {		
		infile >> out;
		
		
		reverse (infile,num, ++count);
		
	}
	
		cout << out << endl;
	

}
int main(int argc, char* argv[]){
	if (argc < 2){
		cerr << "Please enter correct file." << endl;
		return 1;
	}
	else {
		ifstream file(argv[1]);
		if (!file){
			cerr << "Could not open file" << endl;
			return 1;
		}
		int x;
		int y =0;
		file >> x;
		if (file.fail()){
			cerr << "Provide an number at the beginning of the file" <<endl;
			return 1;
		}
		stringstream infile;
		string line;
		while (file >> line){
			infile << line << " ";
		}
		
		reverse(infile, x, y);
		

		return 0;
	}
	
}
