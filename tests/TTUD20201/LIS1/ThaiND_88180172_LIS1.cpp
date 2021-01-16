#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int t, n;

int a[MAXN];

map <int, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        mp.clear();
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int f = mp[a[i] - 1] + 1;
            res = max(res, f);
            mp[a[i]] = max(mp[a[i]], f);
        }
        cout << res << "\n";
    }
}
