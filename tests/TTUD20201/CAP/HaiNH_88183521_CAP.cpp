#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T, n, u, m;
	vector<int> ans;
	cin >> T;
	while (T--) {
		cin >> n;
//		int a[n];
		set<int> a;
		for (int i = 0; i < n; i++) {
			cin >> u;
			a.insert(u);	
		}
		
		cin >> m;
//		int b[m];
		set<int> b;
		for (int i = 0; i < m; i++) {
			cin >> u;
			b.insert(u);	
		}//cin >> b[i];
		int cnt = 0;
		for (auto it: a) {
			int k = it;
			if (b.find(k) != b.end()) cnt++;
		}
		ans.push_back(cnt);
//		cout << cnt << endl;
	}
	
	for (auto it:ans) cout << it << endl;
	return 0;
}

