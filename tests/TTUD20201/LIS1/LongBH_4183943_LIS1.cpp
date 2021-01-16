#include<iostream>
using namespace std;
const int MAX = 1e5;

int main() {
	int t, n, best;
	bool check = false;
	int a[MAX], ans[MAX];
	cin >> t;
	while (t--) {
		best = 1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ans[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] - a[j] == 1) {
					ans[i] = ans[j] + 1;
					check = true;
					break;
				}
			}
			if (check != true) 
				ans[i] = 1;
			check = false;
		}
		
		for (int i = 0; i < n; i++) {
			best = max(best, ans[i]);
		}
		
		cout << best << endl;
	}
}
