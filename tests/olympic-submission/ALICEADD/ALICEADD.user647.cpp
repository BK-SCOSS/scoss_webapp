#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned long long a, b;
		cin >> a >> b;
		unsigned long long c = a / 10 + b / 10 + (a % 10 + b % 10) / 10;
		unsigned long long c0 = (a % 10 + b % 10) % 10;
		if (c) {
			cout << c;
		}
		cout << c0 << endl;
	}
}