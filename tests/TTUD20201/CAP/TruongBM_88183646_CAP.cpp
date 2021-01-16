#include <bits/stdc++.h>
using namespace std;
int dd[107];
int n,m; 
int a[107];
int b[107];

void solve(){
    for(int i = 1; i < 107; i++){
        dd[i] = 0;
    }
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        // dd[a[i]] ++;
    }
    cin >> m;
    for(int i = 1; i <=m; i ++){
        cin >> b[i];
        // dd[a[i]] ++;
    }
    int res = 0;
    // cout <<n << m;
    for(int i = 1; i <=n; i ++){
        for(int j =1; j <=m; j ++){
            if(a[i] == b[j]){
                if(dd[j] == 0){
                    res ++;
                    dd[j] = 1;
                }
                break;
            }
        }
    }
    cout << res;
};

int main(){
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}