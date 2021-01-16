#include<bits/stdc++.h>
using namespace std;
int const N_MAX = 1e5+3;
int n;
int a[N_MAX];
int Max;
void input(){
    cin >> n;
    for(int i= 1; i <= n;i++){
        cin >>  a[i];
    }
}
void solve(){
    input();int res = 0;
    while(n > 1){
        if(n%2 == 0){
            n = n/2;Max = 0;
            for(int i = 1; i <= n;i++){
                a[i] = a[i*2-1] + a[i*2];
                Max = max(Max,a[i]);
            }
            res += Max;
        }
        else{
            n = n/2 + 1;Max = 0;
            for(int i = 1; i < n;i++){
                a[i] = a[i*2-1] + a[i*2];
                Max = max(Max,a[i]);
            }
            a[n] = a[n*2-1];
            Max = max(a[n],Max);
            res += Max;
        }

    }
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
