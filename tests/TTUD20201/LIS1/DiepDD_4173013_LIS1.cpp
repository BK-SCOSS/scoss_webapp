#include <bits/stdc++.h>

using namespace std;

static const int N = 10001;
int t, n, a[N];

int main()
{
    cin >> t;
    while (t--) {
        int res = 0;

        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int f[N];
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = 1;
            for (int j = 1; j < i; ++j) {
                if (a[j]+1 == a[i]) {
                    f[i] = max(f[i], f[j]+1);
                }
            }
            res = max(res, f[i]);
        }

        cout << res << endl;
    }
}
