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

void solve() {
	int Q;
	ull N;
	cin >> Q;
	while (Q--) {
		cin >> N;
		if (N > 1000) cout << 0;
		else {
			ull T = N*(N+1)*(N+2);
			ull Tsq = T*T;
			ull cnt = 0;
			for (int i = 4; i < T; ++i) if (T%i != 0 && Tsq%i == 0) ++cnt;
			cout << cnt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

	return 0;
}