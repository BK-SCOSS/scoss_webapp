#include <bits/stdc++.h>
using namespace std;

int n, x, res;
map <int,int> mapp;

int main() {
	int test;
	cin >> test;

	while (test--) {
		cin >> n;
		mapp.clear();
		res = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			int t = mapp[x-1] + 1;
			res = max(res, t);
			mapp[x] = t;
		}
		cout << res << endl;
	}

}