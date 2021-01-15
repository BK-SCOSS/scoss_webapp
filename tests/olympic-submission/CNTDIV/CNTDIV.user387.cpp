#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int p[N];

map<int, int> getDivs(int u) {
    map<int, int> res;
    while (u > 1) {
        int v = p[u];
        int cnt = 0;
        while (u % v == 0) {
            u /= v;
            cnt++;
        }
        res[v] = cnt;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i; j < N; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        map<int, int> m0 = getDivs(n);
        map<int, int> m1 = getDivs(n + 1);
        map<int, int> m2 = getDivs(n + 2);
        for (auto u : m1) m0[u.first] += u.second;
        for (auto u : m2) m0[u.first] += u.second;
        long long num1 = 1, num2 = 1;
        for (auto u : m0) {
            num1 *= (u.second + 1);
            num2 *= (u.second * 2 + 1);
        }
        cout << (num2 + 1) / 2 - num1 << '\n';
    }
    return 0;
}