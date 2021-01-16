#include <bits/stdc++.h>

int T, n, a[100001];
int i;

using namespace std;

int main(){
	cin >> T;
	for (int p = 0; p < T; p++) {
		cin >> n;
		int res = 0;
		for (i = 0; i < n; i++) cin >> a[i];
		while (n > 1) {
			int tmax = 0, j = 0;
			for (i = 0; i < n/2; i++) {
				a[j] = a[2*i] + a[2*i+1];
				tmax = max(tmax, a[j]);
				j++;
			}
			res += tmax;
			if (n%2 == 1) a[j] = a[n-1];
			n = n/2 + n%2;
		}
		cout << res << endl;		
	}
}
