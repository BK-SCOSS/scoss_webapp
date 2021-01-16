#include<bits/stdc++.h>
using namespace std;

#define MAX_N 101
typedef unsigned long long ull;

int main()   {
	ios::sync_with_stdio(false); cin.tie(0);
	int T,n,m, res;
	ull a[MAX_N], b[MAX_N];
	cin >> T;
	while(T--) {
		res = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> b[i];
			for(int j = 0; j < n; j++) {
				if(a[j] == b[i]) {
					res++;
					break;
				}
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
