#include <bits/stdc++.h>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m, counting = 0;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		long long b[m];
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j]) {
					counting++;
				}
			}
		}
		cout << counting << endl;
	}
	return 0;
}
