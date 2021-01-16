#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10000007];
int cur[10007];;
void input(){
    cin >> n;
    for(int i = 1; i <=n; i ++){
        cin >> a[i];
    }
}
void solve(){
    for(int i = 2; i <= n; i ++){
        for(int j = i; j >= 1; j--){
            if (a[i] - a[j] == 1){
                cur[i] = cur[j] + 1;
                break;
            }
        }
    }
    int max_ = 0;
    for(int i = 1; i <= n; i ++){
        max_ = max(max_, cur[i]);
    }
    cout << max_;
}
int main(){
    int t;
    cin >> t;
    if(t <=0){
        return 0;
    }
    while(t--){
        for(int i =1; i < 10007; i ++){
            cur[i] = 1;
        }
        input();
        solve();
    }
    return 0;
}