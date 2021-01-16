#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int a[100005];
int dp[100005];
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            dp[i] = 1;

            dp[i] = max(dp[i], m[a[i]-1] + 1);

            m[a[i]] = dp[i];

        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
    return 0;
}
