#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 1;

int t, n, m;

int a[MAXN], b[MAXN];

map <int, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
        }
        mp.clear();
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) {
                    if (mp[a[i]]) continue;
                    mp[a[i]] = 1;
                    ++res;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}
