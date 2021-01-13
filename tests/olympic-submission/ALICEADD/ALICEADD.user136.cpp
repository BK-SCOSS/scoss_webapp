#include <iostream>
using namespace std;
int main() {
	
	long int T;
	cin >> T;
	unsigned long long int a[T];
	unsigned long long int b[T];
	unsigned long long int c[T];
	for(long int i = 0; i < T; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for(long int i = 0; i < T; i++) {
		cout << a[i] + b[i] << endl;
	}
	
	return 0;
}
