#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define what_is(x) cerr << #x << " = " << x << '\n';
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef pair<int, int> pii;
typedef vector<pii> vp;


struct fclt {
	int s;
	int d;
	int r;
	
	fclt(int s, int d, int r) {
		this->s = s;
		this->d = d;
		this->r = r;
	}

	bool operator < (fclt &other) { return this->s < other.s; }
};

void solve() {
	int n, K;
	cin >> n >> K;

	ull res = 0;
	vector<fclt> data;

	int s,d,r;
	forn(i, n) {
		cin >> s >> d >> r;
		data.eb(s, d, r);
	}
	sort(all(data));

	vector<ull> dp(n + 1);

	// for (fclt e: data) cerr << e.s << " "; cerr << endl;
	// for (fclt e: data) cerr << e.d << " "; cerr << endl;
	// for (fclt e: data) cerr << e.r << " ";
	// cerr << endl;

	for (int i = 0; i < n; ++i) dp[i] = data[i].r;


	for (int i = 1; i < n; ++i) {
		fclt tmp = data[i];
		for (int j = 0; j < i; ++j) {
			if (data[j].s+data[j].d <= tmp.s - K) {
				dp[i] = max(dp[i], dp[j] + tmp.r);
			}
		}
		// cerr << "max " << i << " " << dp[i] << endl;
		res = max(res, dp[i]);
	}

	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

	return 0;
}