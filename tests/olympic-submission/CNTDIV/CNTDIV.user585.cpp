#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e5+10
//#define int long long
void solve(){
    int n;
    cin>>n;
    long long T = (n + 1)*(n+2)*n;
    long long T2 = T * T;
    long long ans = 0;
    for(int i=1; i<T; i++){
        if(T % i != 0 && T2 % i == 0) ans ++;
    }
    cout<<ans<<endl;
}
//#undef int
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 0x3F
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}