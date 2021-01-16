#include <bits/stdc++.h>

using namespace std;

int t, n, rs;
unsigned long long a[100001];
unsigned long long b[100001];
map<long long, long long> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            b[i] = 1;
            cin >> a[i];
        }
        m[a[1]] = 1;
        unsigned long long rs = 0;
        for (int i = 2; i <= n; ++i) {
             m[a[i]] = i;
             if (m[a[i]-1] != 0) {
                b[i] = max(b[i], b[m[a[i]-1]] + 1);
             }
        }

        for (int i = 0; i < n; ++i) {
            rs = max(rs, b[i]);
        }
        cout << rs << endl;
    }
    return 0;
}

