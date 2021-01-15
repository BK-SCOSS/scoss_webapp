#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 2 * (1e6 + 10);

struct cus{
	ll l, r, v;
	int lq, rq;
} c[N];
                  
bool cmp(pair<ll, int> a, pair<ll, int> b) {
	return (a.fi < b.fi || (a.fi == b.fi && a.se < b.se));
}

bool cmp_cus(cus a, cus b) {
	return (a.lq < b.lq || (a.lq == b.lq && a.rq < b.rq) || (a.lq == b.lq && a.rq == b.rq && a.v < b.v));
}

ll bit[N] = {};

void update(int p, ll val) {
	for (int i = p; i <= N; i += i & (-i)) {
		bit[i] = max(bit[i], val);
	}
}

ll get(int p) {
	ll ans = 0;
	for (int i = p; i; i -= i & (-i)) {
		ans = max(ans, bit[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; ll k;
	cin >> n >> k;

	vector< pair<ll, int> > tmp;

	for (int i = 1; i <= n; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		c[i].l = x;
		c[i].r = x + y + k;
		c[i].v = z;
		tmp.pb({c[i].l, i});
		tmp.pb({c[i].r, i + n});
	}

	sort(tmp.begin(), tmp.end(), cmp);

	int cnt = 1;
	if (tmp[0].se > n) {
		c[tmp[0].se - n].rq = cnt;
	} else {
		c[tmp[0].se].lq = cnt;
	}
	for (int i = 1; i < (int)tmp.size(); i++) {
		if (tmp[i].fi != tmp[i - 1].fi) {
			cnt += 1;
		}
		if (tmp[i].se > n) {
			c[tmp[i].se - n].rq = cnt;	
		} else {
			c[tmp[i].se].lq = cnt;
		}
	}

	sort(c + 1, c + 1 + n, cmp_cus);

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll tmp = get(c[i].lq);
		ans = max(ans, tmp + c[i].v);
		update(c[i].rq, tmp + c[i].v);
	}
	
	cout << ans;
	 	
	return 0;
}