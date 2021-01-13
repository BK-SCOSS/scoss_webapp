#include<iostream>
using namespace std;
int main() {
	int T;
	do { cin >> T;
	}
	while (T > 10 || T < 0);
	unsigned long long int a[1000], b[1000];
	for (int i = 1; i <= T; i++) {
		cin >> a[i] >> b[i];
		cout << a[i] + b[i] << "\n";
	}
}
