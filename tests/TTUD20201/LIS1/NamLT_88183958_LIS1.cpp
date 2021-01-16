#include <iostream>
#define MAX 100000000

using namespace std;

int T, n, an, ans;
int a[MAX], mark[MAX];

int xuLy(int *a) {
	ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mark[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		if (mark[i] == 0) {
			an = 1;
			
			for (int j = i + 1; j < n; j++) {
				if (a[j] == a[i] + an) {
					an += 1;
					mark[j] = 1;
				}
			}
			if (an > ans) {
				ans = an;
			}
		}
	}
	
	cout << ans << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		xuLy(a);
	}
	
	return 0;
}
