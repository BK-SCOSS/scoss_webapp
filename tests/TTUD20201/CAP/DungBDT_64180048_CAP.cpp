#include <bits/stdc++.h>
using namespace std;

int n, m, x, res;
map <int,int> mapp;

int main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		res = 0;
		mapp.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			mapp[x] = 1;
		}
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> x;
			if (mapp[x] == 1) res++;
		}
		cout << res << endl;
	}
}