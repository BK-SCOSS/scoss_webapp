#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e6 + 10;
const ll oo = 1e17;

int n, k;

ll bit[2 * MAXN];

struct data {
    ll s, d, r;
} a[MAXN];

map <ll, int> mp;

vector <ll> rrh;

bool cmp(data a, data b) {
    return a.s < b.s;
}

ll get(int x) {
    ll temp = -oo;
    for (int i = x; i > 0; i -= i & -i) {
        temp = max(temp, bit[i]);
    }
    return temp;
}

void update(int x, ll val) {
    for (int i = x; i < 2 * MAXN; i += i & -i) {
        bit[i] = max(bit[i], val);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].s >> a[i].d >> a[i].r;
        rrh.push_back(a[i].s);
        rrh.push_back(a[i].s + a[i].d + k);
    }
    rrh.push_back(0);
    sort(rrh.begin(), rrh.end());
    int cnt = 0;
    for (int i = 0; i < rrh.size(); ++i) {
        if (!mp[rrh[i]]) mp[rrh[i]] = ++cnt;
    }
    for (int i = 0; i < 2 * MAXN; ++i) bit[i] = -oo;
    sort(a + 1, a + n + 1, cmp);
    ll res = 0;
    update(mp[0], 0);
    for (int i = 1; i <= n; ++i) {
        ll temp = get(mp[a[i].s]) + a[i].r;
        update(mp[a[i].s + a[i].d + k], temp);
        res = max(res, temp);
    }
    cout << res;
}
