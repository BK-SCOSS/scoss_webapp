#include<iostream>

using namespace std;

int main() {
	int T;
	unsigned long long a, b;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}
