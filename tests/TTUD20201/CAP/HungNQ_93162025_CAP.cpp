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

int t, n, m, ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  si c;
  cin >> t >> n;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    c.insert(e);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    if (c.find(e) != c.end()) {
      ans++;
    }
  } 
  cout << ans << endl;  
  return 0;
}
