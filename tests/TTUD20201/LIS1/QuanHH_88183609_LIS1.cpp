#include <bits/stdc++.h>

using namespace std;
int t, n, a[100005], dp[100005];
int main(){
    cin >> t;
    while (t--){
        
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) dp[i] = 1;
        for (int i = 1; i < n; ++i){
            for (int j = i - 1; j >= 0; --j){
                if (a[i] == a[j] + 1){
                    // cout << "a[" << i << "]: " << a[i] << endl;
                    // cout << "a[" << j << "]: " << a[j] << endl;
                    dp[i] = max(dp[i], dp[j] + 1);
                    // cout << "dp: " << dp[i] << endl;
                    // cout << "---------------" << endl;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
        // for (int i = 0; i < n; ++i) cout << dp[i] << ' ';
        // cout << endl;
        cout << ans << endl;
    }
}