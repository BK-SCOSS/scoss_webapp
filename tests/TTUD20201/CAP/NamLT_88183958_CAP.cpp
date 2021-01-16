#include <iostream>
#define MAX 100000000

using namespace std;

int a[MAX], b[MAX], c[MAX];
int n, m, T, ans;

int xuLy(int k) {
	ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				ans += 1;
				break;
			}
		}
	}
	
	c[k] = ans;
}

int main() {
	cin >> T;
	for (int k = 1; k <= T; k++) {
		xuLy(k);
	}
	
	for (int i = 1; i <= T; i++) {
		cout << c[i] << endl;
	}
	return 0;
}
