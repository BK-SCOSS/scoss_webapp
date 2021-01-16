#include <bits/stdc++.h>
#define MAX 105
using namespace std;
int a[MAX], b[MAX], ok[MAX];
int n, m, t;
int main() {
	//freopen("A.inp", "r", stdin);
	//freopen("A.out", "w", stdout);
	cin >> t;
	while(t--) {
		int ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(b, b+m);
		//for(int i = 0; i < n; i++);
		//int j = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i] == b[j] && ok[j] == 0) {
					ans++;
					ok[j] = 1;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}