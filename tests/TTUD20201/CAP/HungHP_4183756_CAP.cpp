#include<bits/stdc++.h>
using namespace std;
int const MAX = 1200;
int n,m;
int a[MAX],b[MAX];
int cnt;set<int> S;
void input(){
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m;i++){
        cin >> b[i];
    }
}
void solve(){
    input();
    cnt = 0;
    S.clear();
    for(int i = 1; i<=n;i++){
        for(int j = 1; j <= m;j++){
            if(a[i] == b[j]){
                S.insert(a[i]);
                break;
            }
        }
    }
    cnt = S.size();
    cout << cnt << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;

}
