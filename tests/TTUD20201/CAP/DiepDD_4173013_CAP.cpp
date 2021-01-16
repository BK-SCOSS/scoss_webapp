#include <bits/stdc++.h>

using namespace std;

static const int N = 101;
int t, n , a[N], m, b[N];

int main()
{
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
        }

        sort(a+1, a+n+1);
        sort(b+1, b+m+1);

        if (n < m) {
            for (int i = 1; i <= n; ++i) {
                if ((i == 1) || a[i] != a[i-1]) {
                    if (binary_search(b+1, b+m+1, a[i])) {
                        cnt++;
                    }
                }
            }
        } else {
            for (int i = 1; i <= m; ++i) {
                if ((i == 1) || a[i] != a[i-1]) {
                    if (binary_search(a+1, a+n+1, b[i])) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}
