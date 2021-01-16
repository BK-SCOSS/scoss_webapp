#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define ll long long

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n, a[MAXN], b;
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> b;
            for (int j = 0; j < n; ++j) {
                if (b == a[j]) {
                    res++;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}