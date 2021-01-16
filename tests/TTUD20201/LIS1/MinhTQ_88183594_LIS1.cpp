#include <bits/stdc++.h>
#define MAX 100005
#define MAXV 1000005
using namespace std;

int t, n;
int a[MAX];
int dp[MAX];
int lis[MAXV];

int main() {
	//freopen("B.inp", "r", stdin);
	//freopen("B.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			
		}
		
		for(int i = 0; i < MAXV; i++)
			lis[i] = -1;
		dp[0] = 1;
		lis[a[0]%MAXV] = 0;
		for(int i = 1; i < n; i++) {
			if(lis[(a[i]-1)%MAXV] == -1) {
				dp[i] = 1;
				lis[(a[i])%MAXV] = i;
			}
			else {
				dp[i] = 1+dp[lis[(a[i]-1)%MAXV]];
				lis[a[i]%MAXV] = i;	
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
}