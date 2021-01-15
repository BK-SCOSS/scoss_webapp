#include<bits/stdc++.h>
using namespace std;

int main() {
	int T, a, b;
	cin >> T;
	vector<int> res(T);
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		res[i] = a + b;
	}
	for (int i: res) {
		cout << i << "\n";
	}
	return 0;
}
