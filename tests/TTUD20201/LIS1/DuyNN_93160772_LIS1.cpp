#include <iostream>
using namespace std;
int t, n, result = 0;
int a[100000];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int i = 0;
		while (i < n) {
			int cnt = 1;
			int tmp = a[i];
			for (int j = i; j < n; j++) {
				if (a[j] - 1 == tmp) {
					cnt++;
					tmp = a[j];
				}
			}
			result = result > cnt ? result : cnt;
			i++;
		}
		cout << result;
	}
}