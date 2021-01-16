#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define each(x, a) for (auto& x: a)
#define all(c) (c).begin(), (c).end()
typedef unsigned long long      ull;
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef vector<ii>              vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;
typedef map<int, int>           mii;

int t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi dp(n, 1);
    vi a(n);
    each(e, a) {
      cin >> e;
    };
    mii pos;

    int ans = dp[0];
    pos[a[0]] = 0;
    for (int i=1; i<n; i++) {
      pos[a[i]] = i;
      if (pos.find(a[i] - 1) != pos.end()) {
        int pos_prev = pos[a[i] - 1];
        dp[i] = dp[pos_prev] + 1;
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
