#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct Item {
    int s, d, r;

    bool operator < (const Item &o) const {
        return s < o.s;
    }
};

Item a[N];
int n, k;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].s >> a[i].d >> a[i].r;
    }
    sort(a, a + n);
    map<int, int64_t> f;
    int64_t best = 0;
    auto get = [&] (int till) {
        while (!f.empty() && f.begin()->first <= till) {
            best = max(best, f.begin()->second);
            f.erase(f.begin());
        }
        return best;
    };
    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        int64_t now = get(a[i].s - k) + a[i].r;
        f[a[i].s + a[i].d] = max(f[a[i].s + a[i].d], now);
        res = max(res, now);
    }
    cout << res << endl;
    return 0;
}