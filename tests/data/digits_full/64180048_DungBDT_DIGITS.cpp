#include <bits/stdc++.h>
using namespace std;

int cal(int n, int t) {
    int res = 0;
    bool a[12];
    memset(a, true, sizeof(a));
    a[t] = false;

    for (int s = 1; s <= 9; ++s) if (a[s]) { a[s] = false;
    for (int h = 1; h <= 9; ++h) if (a[h]) { a[h] = false;
    for (int u = 0; u <= 9; ++u) if (a[u]) { a[u] = false;
    for (int o = 0; o <= 9; ++o) if (a[o]) { a[o] = false;
    for (int i = 0; i <= 9; ++i) if (a[i]) { a[i] = false;
    for (int c = 0; c <= 9; ++c) if (a[c]) { a[c] = false;
        if (s * 1001 + (h+o) * 100 + (u + i) * 10 + c == n) res++;
    a[c] = true;} a[i] = true;} a[o] = true;} a[u] = true;} a[h] = true;} a[s] = true;}
    return res;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        if (n % 2 || n > 99999+9999 || n < 10000 + 1000) {
            cout << "0" << endl;
            continue;
        }
        cout << cal(n / 10, n % 10 / 2) + cal(n / 10 - 1, n % 10 / 2 + 5) << endl;
    }
}
