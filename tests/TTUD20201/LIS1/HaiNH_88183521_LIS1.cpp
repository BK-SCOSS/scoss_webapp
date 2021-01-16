#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n, res = 0;
	cin >> T;
	while(T--) {
		res = 1;
		map<int, int> m;
		cin >> n;
		int u;
		for (int i = 1; i <= n; i++) {
			cin >> u;
			if (m.find(u-1) != m.end()) {
				auto k = m.find(u-1);
				if(m.find(u) != m.end()) {
					auto p = m.find(u);
					p->second = k->second+1;
				}
				else {
//					auto k = m.find(u-1);
					m.insert({u, (k->second)+1});	
				}
				

				
			}
			else {
				m.insert({u, 1});
			}			
			
		}
		
		for (auto it:m) {
			res = max(res, it.second);
		}

		cout << res << endl;
		
		
	}
	return 0;
}

