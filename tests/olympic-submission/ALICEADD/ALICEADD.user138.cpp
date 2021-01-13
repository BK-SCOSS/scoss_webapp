#include <iostream>

using namespace std;

int main() {
	unsigned int T;
	unsigned long int a, b;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		fflush(stdin);
		cin >> a;
		cin >> b;
		cout << a + b << endl;
	}
	return 0;
}
