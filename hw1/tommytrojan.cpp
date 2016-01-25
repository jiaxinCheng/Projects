#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;
  string o;
  getline(input, o);
  stringstream u;
  u<<o;
  u>> floors;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];
  int **numpro = new int* [floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  numpro[i] = NULL;
  }

  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
		  	if (i > floors|| i <1){
		  		output << "Error - floor " << i << " does not exist" <<endl;
		  	}
		  	else if (trojans[i-1] != NULL){
		  		output << "Error - floor " << i  << " is not empty" << endl;
		  	}
		  	else{
		  		floorsizes[i-1] = k;
		  		trojans[i-1] = new string *[k];
		  		for (int j =0; j< k; j++){
		  			trojans[i-1][j] = NULL;
		  		}
		  		numpro[i-1] = new int [k];
		  	}
		  }
	  }
	  else if (curr == "MOVEOUT") {
	  	 if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		 else{
		  		int i;
	  			ss >> i;
	  			if (i  > floors || i <1){
	  				output << "Error - floor " << i << " does not exist" << endl;
	  			}
	  			else if (trojans[i-1] == NULL){
	  				output << "Error - floor " << i << " is empty" <<endl;
	  			}
	  			 
	  			else{
	  				for (int j =0; j < floorsizes[i-1]; j++){
	  					delete[] trojans[i-1][j]; 
	  					
	  					}
	  			
	  				delete[] trojans[i-1];
	  				trojans[i-1] = NULL;
	  				if (numpro[i-1] != NULL){
	  					delete[] numpro[i-1];
	  					numpro[i-1] =NULL;
	  				}
	  				floorsizes[i-1] =0;
	  			}
		  
	  	
	  		}
		}
	  else if (curr == "OBTAIN") {
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
	  	else{
	  		int i, j,k;
	  		ss >> i;
	  		ss >> j;
	  		ss >> k;

	  		if (j > floorsizes[i-1] || trojans[i-1] == NULL || j <1){
	  			output << "Error - there is no student " << j <<endl;
	  		}
	  		else if ( i < 1 || i > floors){
	  			output << "Error - floor " << i  <<" does not exist" << endl;
	  		}
	  		else if (trojans[i-1][j-1] != NULL){
	  			output << "Error - the student" << i << " " << j <<" already has properties" <<endl;
	  		}
	  		else {
	  				trojans[i-1][j-1] = new string [k];
	  				numpro[i-1][j-1] = k;
	  				for (int c =0; c <k; c++){
	  					ss >> trojans[i-1][j-1][c];
	  			}
	  		}

	  }
	}
	  else if (curr == "OUTPUT") {
	  	int i,j;
	  		ss >> i;
	  		ss >> j;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		else{ 
	  		
	  		if ( i > floors ||i <1){
	  			output << "Error - there is no floor " << i << endl;
	  		}
	  		else if ( j > floorsizes[i-1] || j < 1){
	  			output << "Error - there is no student " << j << endl;
	  		}
	  		else if (trojans[i-1][j-1] == NULL){
	  			output << "Error - there is no position " << i << " " << j << " avalible." << endl;
	  		}
	  		else{
	  			for (int z =0; z < numpro[i-1][j-1]; z++){
	  				output<< trojans[i-1][j-1][z] << endl;
	  			}
	  		}
	  	}
	  }
	  else {
	  	output << "Error - provide correct command" << endl;
	  }
  }

  for (int v =0;v <floors;v++){
  	if (numpro[v] !=NULL){
  		delete[] numpro[v];
  		numpro[v] =NULL;
  	}
  	if(trojans[v] !=NULL){
  		for (int n=0;n < floorsizes[v];n++){
  			if (trojans[v][n]!= NULL){
  				delete[] trojans[v][n];
  				trojans [v][n] =NULL;
  			}
  		}
		delete[] trojans[v];
		trojans[v] =NULL;
  	} 		
  }
  delete[] trojans;
  delete[] floorsizes;

  delete[] numpro;

  
  return 0;
}