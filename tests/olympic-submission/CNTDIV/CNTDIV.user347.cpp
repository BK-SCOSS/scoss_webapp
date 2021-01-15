#include <bits/stdc++.h>

using namespace std;

void go(int n, map<int, int> &f) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            f[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        f[n]++;
    }
}

int64_t calc(const map<int, int> &f) {
    int64_t res = 1;
    for (auto it : f) {
        res *= it.second + 1;
    }
    return res;
}

int64_t solve(int n) {
    map<int, int> f;
    go(n, f);
    go(n + 1, f);
    go(n + 2, f);

    int64_t res = -calc(f);

    for (auto &it : f) {
        it.second *= 2;
    }
    res += calc(f) / 2 + 1;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int Q; cin >> Q;
    while (Q--) {
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}