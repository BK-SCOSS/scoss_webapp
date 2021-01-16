#include <bits/stdc++.h>

using namespace std;

int a[100000];
int dp[100000];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        int longest = -1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == a[i] - 1) {
                        dp[i] = dp[j] + 1;
                        break;
                }
                else continue;
            }
            longest = max(longest, dp[i]);
        }
        cout << longest << endl;
    }
    return 0;
}
