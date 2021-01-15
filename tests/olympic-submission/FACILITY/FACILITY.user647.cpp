#include <bits/stdc++.h>

using namespace std;


int const N = 1e6 + 5;

struct Customer
{
	int start, end, r;
	Customer(){}
	Customer(int start, int end, int r):start(start), end(end), r(r){}
 	bool operator < (const Customer p) const {
		if (end != p.end) {
			return end < p.end;
		}
		return start < p.start;
	}
};

Customer a[N];
long long dp[N], maxs[N];


int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int s, d, r;
		cin >> s >> d >> r;
		a[i] = Customer(s, s + d, r);
	}

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int pos = upper_bound(a + 1, a + n + 1, Customer(0, a[i].start - k + 1, 0)) - a - 1;
		// cout << a[pos].end << " " << a[i].start << endl;
		dp[i] = maxs[pos] + a[i].r;
		maxs[i] = max(maxs[i - 1], dp[i]);
	}

	cout << maxs[n] << endl;
}