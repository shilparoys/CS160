#include <iostream>
#include <fstream>
using namespace std;

ofstream myfile;
void writeToFile(int n){
	myfile << n << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			myfile << ((rand() % 9) + 1) << " ";
		}
		myfile << endl;
	}

	myfile << "---" << endl;
}

int main(){
  	myfile.open("matrices.txt");
	writeToFile(10);
	writeToFile(10);
	writeToFile(20);
	writeToFile(20);
	myfile.close();
	return 0;
}
