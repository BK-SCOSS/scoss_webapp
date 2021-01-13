#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1000010;


int n, k;

struct Data {
    int l, r;
    int w;

    bool operator < (const Data &o) const {
        if (r != o.r) return r < o.r;
        return make_pair(l, w) < make_pair(o.l, o.w);
    }
} a[N];

int dp[N];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int s, d, r;
        cin >> s >> d >> r;
        a[i] = {s, s + d + k - 1, r};
    }
    sort(a + 1, a + n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        Data cur = {0, a[i].l, 0};
        int pos = lower_bound(a + 1, a + n + 1, cur) - a;
        dp[i] = a[i].w + dp[pos - 1];
        dp[i] = max(dp[i], dp[i - 1]);
        // cout << i << ' ' << pos << ' ' << dp[i] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}