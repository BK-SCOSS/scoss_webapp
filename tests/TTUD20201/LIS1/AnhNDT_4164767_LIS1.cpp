#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pob pop_back
int t, n;
map<int,int> dp;
int a[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        dp[a[0]] = 1;
        for(int i = 1;i < n;i++){
            dp[a[i]] = max(dp[a[i]-1]+1,dp[a[i]]);
            ans = max(ans,dp[a[i]]);
        }
        cout << ans << endl;
    }


    return 0;
}
