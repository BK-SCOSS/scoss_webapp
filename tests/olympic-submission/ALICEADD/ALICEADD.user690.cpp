#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;
	while (ntest--) {
		ull a, b;
		cin >> a >> b;
	 
		ull x = a / 10 + b / 10;
		ull y = a % 10 + b % 10;
	 
		if (y >= 10) {
			x += 1;
			y -= 10;
		}
	 
		if (x > 0) cout << x;
		cout << y;
		cout << endl;
	}

	return 0;
}