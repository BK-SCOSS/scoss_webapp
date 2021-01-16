#include<iostream>
#include<vector>
using namespace std;
int t, n, m, result = 0, maxA = 0, maxB = 0;
int mark[100000] = { 0 };
int a[101], b[101];
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			maxA = max(maxA, a[i]);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			maxB = max(maxB, b[i]);
		}
		/*for (int i = 0; i < n; i++) {
			mark[a[i]] += 1;
		}
		for (int i = 0; i < m; i++) {
			if (mark[b[i]] != 0)
				result += mark[b[i]];
		}*/
		for (int i = 0; i<n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j]) {
					result++;
					break;
				}
			}
		}
		cout << result << endl;
	}
}