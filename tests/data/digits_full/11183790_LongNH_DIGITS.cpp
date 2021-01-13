#include <bits/stdc++.h>
using namespace std;
int X[7];
int appeared[9];
int ans,N,M;
void solution(){
int T = X[0]*1000 + X[1]*100 + X[2]*10 + X[3] + X[2]*10000 + X[4]*1000 + X[5]*100 + X[6]*10 + X[4];
if(T == N){
    ans++;
}
}
void input(){
    cin >> M;
    for(int i = 1; i <= M; i++) cin >> N >> endl;
    for(int v = 1; v <= 9; v++) appeared[v] = 0;
}
void TRY(int k){
    for(int v = 1; v <= 9; v++){
    if(appeared[v] == 0){
    X[k] = v;
    appeared[v] = 1;
    if(k == 6){
        solution();
}else{
    TRY(k+1);
}
    appeared[v] = 0;
}
}
}
void solve(){
    input();
    ans = 0;
    TRY(0);
    cout << ans << endl;
}
int main(){
    solve();
}