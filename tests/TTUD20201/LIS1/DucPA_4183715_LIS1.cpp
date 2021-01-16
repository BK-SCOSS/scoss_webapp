#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int test,dp[MAX],a[MAX],b[MAX], n, ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> test;
    while(test--){
            ans = 1;
        cin >> n;
        for( int i = 0; i < n; i++) {
            dp[i] = 0;
            b[i] = 0;
        }
        for( int i = 0; i < n; i++) cin >> a[i];
        dp[0] = 1;
        for( int i = 1; i < n; i++){
            dp[i] = -1;
            for( int j = 0; j < n; j++){
                if( a[i] - a[j] == 1) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max( ans, dp[i]);
        }
    cout << ans;
  }
}
