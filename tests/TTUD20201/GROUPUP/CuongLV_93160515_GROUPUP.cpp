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
		vector<int> a(10000);

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int result = 0;
		while (n>1) {
			if (n % 2 == 0) {
				int maxA = 0;
				for (int i = 1; i <= n; i++) {
					a[i] = a[i*2] + a[i*2 - 1];
					maxA = max(a[i], maxA);
				}
				result = result + maxA;
				n = n /2;
			}
			else {
				int maxA = 0;
				for (int j = 1; j <= n; j ++) {
					a[j] = a[j*2] + a[j*2 - 1];
					maxA = max(a[j], maxA);
				}
				result = result + maxA;
				n = n /2 + 1;
			}
		}

		cout << result;
		result = 0;
	}
	return 0;
}