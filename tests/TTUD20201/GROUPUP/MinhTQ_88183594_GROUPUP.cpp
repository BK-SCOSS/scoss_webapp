#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int t, n, a[MAX];
int main() {
	//freopen("C.inp", "r", stdin);
	//freopen("C.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int numgroup = n;
		int ans = 0;
		while(numgroup > 1) {
			int max_now = 0;
			if(numgroup%2 == 0) {
				for(int i = 0; i < numgroup; i+=2) {
					a[i] = a[i]+a[i+1];
				}
				numgroup = numgroup/2;
				for(int i = 0; i < numgroup; i++) {
					a[i] = a[i*2];
					max_now = max(max_now, a[i]);
				}
				ans += max_now;
			}
			else {
				for(int i = 0; i < numgroup-1; i+=2) {
					a[i] = a[i]+a[i+1];
				}
				numgroup = numgroup/2+1;
				for(int i = 0; i < numgroup; i++) {
					a[i] = a[i*2];
					max_now = max(max_now, a[i]);
				}
				ans += max_now;
			}
		}
		cout << ans << "\n";
	}
}