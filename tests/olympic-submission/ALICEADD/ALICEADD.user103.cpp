#include <iostream>

using namespace std;


int main() {

	int T;
	cin >> T;
	unsigned long long int a[10];
	unsigned long long int b[10];
	for (int i = 0; i < T; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < T; i++) {
		cout << (a[i] + b[i]) << endl;
	}


	return 0;
}