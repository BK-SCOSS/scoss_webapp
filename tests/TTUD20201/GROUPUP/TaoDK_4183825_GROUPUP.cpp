#include<bits/stdc++.h>
using namespace std;

int T;
int n;
queue<int> a;
int temp;

void solve(){
    int ans = 0;
    int cnt = 0;
    int res = 0;
    while(!a.empty()){
        if(n == 1){
            a.pop();
            break;
        }
        int u = a.front();
        a.pop();
        cnt++;
        if(cnt == n){
            n = n / 2 + 1;
            cnt = 0;
            ans += res;
            a.push(u);
            continue;
        }
        int v = a.front();
        a.pop();
        cnt++;
        res = max(res, u + v);
        a.push(u + v);
        if(cnt == n){
            n = n / 2;
            cnt = 0;
            ans += res;
        }
    }
    cout << ans << endl;
}
void input(){
    cin >> T;
    while(T > 0){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> temp;
            a.push(temp);
        }
        solve();
        T--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}
