#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[100000];
int dp[1000005];
int res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(dp, 0, sizeof(dp));
        res = 1;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        if (n > 1000) {
            for (int j = n - 1; j >= 0; j--) {
                dp[a[j]] = dp[a[j] + 1] + 1;
                res = max(res, dp[a[j]]);
            }
        } else {
            for (int j = 0; j < n; j++) {
                int counts = 1;
                int base = a[j];
                for (int k = j + 1; k < n; k++) {
                    if (a[k] == base + 1) {
                        counts++;
                        base = a[k];
                    }
                }
                res = max(res, counts);
            }
        }

        cout << res << endl;
    }
}
