#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100007
typedef unsigned long long ull;

ull n, a[MAX_N], res;
ull kqua[MAX_N];

ull find_kqua(int k) {
	for(int i = k-1; i >= max(0, k-10000); i--) {
		if(a[k] - a[i] == 1) {
			return kqua[i] + 1;
		}
	}
	return 1;
}

int main()   {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		res = 0;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			kqua[i] = find_kqua(i);
			if(kqua[i]>res) res = kqua[i];
		}
		cout << res << endl;
	}
	return 0;
}
