#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e6+10
#define int long long
int n, k;
struct guest{
    int s, d, r, fi;
};
int dp[MAX];
guest a[MAX];
bool cmp(guest x, guest y){
    return x.s < y.s;
}
void solve(){
    cin>>n>>k;
    for(int i=1 ; i<=n; i++){
        cin>>a[i].s>>a[i].d>>a[i].r;
        a[i].fi = a[i].s + a[i].d + k;
    }
    sort(a+1, a+n+1, cmp);
    dp[1] = a[1].r;
    for(int i=2; i<=n; i++){
        int j = i-1;
        while(j >= 1 && a[i].s < a[j].fi){
            j --;
        }
        dp[i] = max(dp[j] + a[i].r, dp[i - 1]);
    }
    cout<<dp[n]<<endl;
}
#undef int
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 0x3F
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}