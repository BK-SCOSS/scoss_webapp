#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
struct info {
	int l, r, a;
} order[N];

struct BinaryIndexedTree {
	long long T[2*N];
	void update(int k, long long w) { for (; k <= 2 * n; k += k & (-k)) T[k] = max (T[k], w); }
	long long get(int k) { long long res = 0; for (; k > 0; k -= k & (-k)) res = max (res, T[k]); return res; }
} BIT;

int main() {
	ios :: sync_with_stdio (0);
	cin.tie (0);  cout.tie (0);

	if (fopen ("main.in", "r"))
		freopen ("main.in", "r", stdin);

	cin >> n >> k;
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		info &t = order[i];
		cin >> t.l >> t.r >> t.a;
		t.r = t.l + t.r + k - 1;
		v.push_back (t.l);
		v.push_back (t.r);
	}

	sort (v.begin(), v.end());
	v.erase (unique(v.begin(), v.end()), v.end());

	sort (order+1, order+1+n, [] (info A, info B) {
		if (A.l != B.l) return A.l < B.l;
		return A.r < B.r;
	});

	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int L = lower_bound(v.begin(), v.end(), order[i].l) - v.begin() + 1;
		int R = lower_bound(v.begin(), v.end(), order[i].r) - v.begin() + 1;
		long long bst = BIT.get(L-1) + order[i].a;
		res = max (res, bst);
		BIT.update (R, bst);
	}

	cout << res << '\n';

	return 0;
}
