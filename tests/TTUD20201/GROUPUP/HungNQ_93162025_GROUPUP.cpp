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

int t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n;
    int ans = 0;
    cin >> n;
    vi a(n);
    each(e, a) {
      cin >> e;
    };
    
    vi temp;
    int length;
    while (1) {
      int sum = 0;
      if (a.size() == 1) {
        break;
      };
      for (int i = 0; i < a.size(); i+=2) {
        if (i == a.size() - 1) {
          temp.pb(a[i]);
        } else {
          temp.pb(a[i] + a[i+1]);
          sum = max(sum, a[i] + a[i+1]);
        }
      }
      a = temp;
      temp = vi();
      ans += sum;
    }
    cout << ans << endl;
  }
  
  return 0;
}
