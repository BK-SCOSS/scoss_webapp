#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
        int a[100005];
        for (int i=0; i<n; i++) cin >> a[i];
        int dp[100005];
        for (int i=0; i<n; i++) dp[i] = 1;
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++)
                if (a[i]==a[j]+1)
                    dp[i]=dp[j]+1;
        }
        int res = 0;
        for (int i=0; i<n; ++i) res = max(res,dp[i]);
        cout << res << endl;
    }
    return 0;
}

