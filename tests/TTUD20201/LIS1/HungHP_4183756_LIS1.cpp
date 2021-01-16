#include<bits/stdc++.h>
using namespace std;
int const N_MAX = 1e5+3;
int n;
int a[N_MAX];
int dp[N_MAX];
void input(){
    cin >> n;
    for(int i= 1; i <= n;i++){
        cin >> a[i];
        dp[i] =-1;
    }
}
int LIS(int x){
    int res = 1;
    if(x == 1) return 1;
    if(dp[x] != -1) return dp[x];
    for(int j = 1;j <x;j++){
        if(a[j] == a[x] -1){
            res = max(res,LIS(j) +1);
        }
    }
    return dp[x] = res;
}
void solve(){
    input();int res = 1;
    for(int i = 1; i <=n;i++){
        res = max(res,LIS(i));
    }
    cout << res << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
