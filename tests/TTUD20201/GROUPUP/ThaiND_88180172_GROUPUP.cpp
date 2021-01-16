#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 1;

int t, n;

int a[MAXN], s[MAXN];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        int res = 0;
        int i = 2;
        for (; i <= n; i *= 2) {
            int maxS = 0;
            for (int j = 1; j <= n; j += i) {
                maxS = max(maxS, s[min(n, j + i - 1)] - s[j - 1]);
            }
            res += maxS;
        }
        if (i / 2 != n) res += s[n];
        cout << res << "\n";
    }
}
