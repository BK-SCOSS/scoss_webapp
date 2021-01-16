#include <iostream>
#include <vector>
#include<bits/stdc++.h>;
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> f(n);
		int result = 1;
		for (int i = 0; i<n; i++) {
			f[i] = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] > a[j] && a[i] == a[j]+1 ) {
					f[i] = max(f[i], f[j]);
				}
			}
			f[i] += 1;
			result = max(result, f[i]);
		}

		cout << result;
	}
	return 0;
}