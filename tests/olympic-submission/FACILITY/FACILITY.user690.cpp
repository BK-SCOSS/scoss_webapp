#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct Choice {
	int l, r, val;
};

Choice c[N];
int n, k;
long long dp[N];

bool cmp(Choice x, Choice y) {
	return x.r < y.r;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].l >> c[i].r >> c[i].val;
		c[i].r += c[i].l;
	}

	sort(c + 1, c + n + 1, cmp);

	vector<int> r;
	r.push_back(-1e9);
	for (int i = 1; i <= n; i++) {
		r.push_back(c[i].r);
	} 

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		int ti = c[i].l - k;
		int k = upper_bound(r.begin(), r.end(), ti) - r.begin() - 1;
		dp[i] = max(dp[i], dp[k] + c[i].val);
	}

	cout << dp[n] << endl;

	return 0;
}