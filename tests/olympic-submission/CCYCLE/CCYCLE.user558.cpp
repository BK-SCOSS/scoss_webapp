#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e4 + 1;
const int MAXL = 1e3 + 1;
const int MOD = 1e9 + 7;

int n, l, s, t;

int memo[3 * MAXN][MAXL];

int solve(int u, int re) {
    if (re > l) return 0;
    if (re == l) return u == t;
    if (memo[u][re] != -1) return memo[u][re];
    int cur = 0;
    if (u % 3 == 0) {
        cur += solve(u - 2, re + 1); cur %= MOD;
        cur += solve(u == 3 * n ? 1 : u + 1, re + 1); cur %= MOD;
    } else if (u % 3 == 1) {
        cur += solve(u == 1 ? 3 * n : u - 1, re + 1); cur %= MOD;
        cur += solve(u + 1, re + 1); cur %= MOD;
        cur += solve(u + 2, re + 1); cur %= MOD;
    } else {
        cur += solve(u - 1, re + 1); cur %= MOD;
    }
    return memo[u][re] = cur;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> s >> t;
    memset(memo, -1, sizeof(memo));
    cout << solve(s, 0);
}
