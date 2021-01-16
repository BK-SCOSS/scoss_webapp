#include <bits/stdc++.h>
using namespace std;

int n, res;
int a[100100];

int main() {
	int test;
	cin >> test;

	while (test--) {
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];

		while (n > 1) {
			int tmp = 0;
			for (int i = 1; i <= n/2; ++i) {
				a[i] = a[2 * i -1] + a[2 * i];
				tmp = max(tmp, a[i]);
			}
			if (n % 2 == 1) a[n/2+1] = a[n];
			n = (n+1)/2;
			res += tmp;
		}
		cout << res << endl;
	}
}