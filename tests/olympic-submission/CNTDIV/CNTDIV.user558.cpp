#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e6 + 10;

int q, n;

int h[MAXN];

map <int, int> mp;

void prepare() {
    for (int i = 2; i * i < MAXN; ++i) {
        if (!h[i]) {
            for (int j = 0; i * i + i * j < MAXN; ++j) {
                h[i * i + i * j] = i;
            }
        }
    }
    for (int i = 2; i < MAXN; ++i) if (!h[i]) h[i] = i;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    cin >> q;
    while (q --> 0) {
        cin >> n;
        mp.clear();
        for (int i = n; i <= n + 2; ++i) {
            int x = i;
            while (x > 1) {
                ++mp[h[x]];
                x /= h[x];
            }
        }
        ll cnt1 = 1, cnt2 = 1;
        for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); ++it) {
            cnt1 *= 1ll * (2 * it -> second + 1);
            cnt2 *= 1ll * (it -> second + 1);
        }
        cnt1 = (cnt1 - 1) / 2;
        --cnt2;
        cout << cnt1 - cnt2 << "\n";
    }
}
