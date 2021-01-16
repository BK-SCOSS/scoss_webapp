#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100007
typedef unsigned long long ull;

int main()   {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	int n, a[MAX_N];
	cin >> T;
	while(T--) {
		ull res = 0, curr_max;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		while(n > 1) {
			curr_max = 0;
			for(int i = 0; i < n/2; i++) {
				a[i] = a[2*i] + a[2*i+1];
				if(a[i]>curr_max) curr_max = a[i];
			}
			res+=curr_max;
			if(n%2 == 0) n = n/2;
			else {
				a[n/2] = a[n-1];
				n = n/2 + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
