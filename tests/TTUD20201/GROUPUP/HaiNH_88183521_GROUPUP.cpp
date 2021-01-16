#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		queue<int> q, q2;
		
		int ans = 0, u, final_ans = 0;
		cin >> n;
//		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> u;
			q.push(u);
		}
		
		
		while (q.size() != 1) {
			int n = q.size();
			ans = 0;
			for (int i = 0; i < n/2; i++) {
				int tmp1 = q.front();
				q.pop();
				tmp1 += q.front();
				q.pop();
				ans = max(ans, tmp1);
		
				q2.push(tmp1);
			}
			
			
			if (!q.empty()) {
				int tmpp = q.front();
				q.pop();
				q2.push(tmpp);
			}
			final_ans += ans;
			
			while(!q2.empty()) {
				int tmp3 = q2.front();
				q2.pop();
				q.push(tmp3);
			}
			
		}
//		for (auto it:q) cout << it << " ";
		
				
		
		cout << final_ans << endl;
		
		
		
		
	}
	return 0;
}

