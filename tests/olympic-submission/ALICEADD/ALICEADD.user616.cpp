#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n;
	
	ifstream input; 
	input.open("test.txt");
	input >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		input >> a[i] >> b[i];
	}
	input.close();
	
	ofstream output;
	output.open("answer.txt");
	for (int i = 0; i < n; i++) {
		output << a[i] + b[i] << endl;
	}
	output.close();
	
	return 0;
}
