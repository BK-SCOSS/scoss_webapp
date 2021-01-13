#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
	int T;
	cin >> T;
	unsigned long long int a[T], b[T];
	for (int i = 0; i < T; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 0; i < T; i++) {
		cout << (a[i] + b[i]) << +"\n";
	}
	return 0;
}
