#include <iostream>
using namespace std;
int a[100005] = {};
int T, n;
int main() {
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> n;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int check = n;
		while (check != 1) {
			int maxTime = 0;
			int i = 1;
			if (check % 2 == 0) {
				check /= 2;
				for (int j = 1; j <= check * 2; j = j + 2) {
					int k = a[j] + a[j + 1];
					a[i] = k;
					maxTime = max(maxTime, a[i]);
					i++;
				}
			}
			else {
				check = check / 2 + 1;
				for (int j = 1; j <= check * 2 - 1; j = j + 2) {
					if (j == check * 2 - 1) a[i] = a[j];
					else a[i] = a[j] + a[j + 1];
					maxTime = max(maxTime, a[i]);
					i++;
				}
			}
			res += maxTime;
		}
		cout << res << endl;
	}
}