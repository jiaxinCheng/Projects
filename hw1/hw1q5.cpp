#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;
void reverse(stringstream &infile,int num, int count){
	string out;
	//bool print = false;
	if (count == num){
		//print = true;
		return;
	}
	else {		
		infile >> out;
		//++count;
		
		reverse (infile,num, ++count);
		//cout<<out << endl;
	}
	//if (print){
		cout << out << endl;
	//}
	/*if (check){
		print(out);		
	}*/
	/*if (infile >> out || count < num || count == num){
		return reverse (infile);
	}
	else {
		return out;
	}*/

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
		//cout << a;

		return 0;
	}
	
}
