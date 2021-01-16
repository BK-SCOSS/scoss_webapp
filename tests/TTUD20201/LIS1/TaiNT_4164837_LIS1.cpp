#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5+3;

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--){
        int n;
        long long a[INF];
        map<long long, int> dp;
        
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        dp[a[0]] = 1;
        int ans = 1;
        for(int i=1; i<n; i++){
            // int maxx = 0;
            // for(int j=0; j<i; j++){
            //     if(a[i] - a[j] == 1){
            //         if(s[j] > maxx) maxx = s[j];
            //     }
            // }
            dp[a[i]] = max(dp[a[i]], dp[a[i]-1] + 1);
            if(dp[a[i]] > ans) ans = dp[a[i]];
        }
        cout << ans << endl;        
    }
    return 0;
}