#include<bits/stdc++.h>
using namespace std;

int X[7];// X[0] = H, X[1] = U, X[2] = S, X[3] = T, X[4] = O, X[5] = I, X[6] = C
int appeared[10];
int ans,N, T;

void solution(){
    int T = X[0]*1000 + X[1]*100 + X[2]*10 + X[3] + X[2]*10000 + X[4]*1000 + X[5]*100 + X[6]*10 + X[3];
    if(T == N && X[0] > 0 && X[2] > 0){
        ans++;
    }
}

void init(){
    for(int v = 0; v <= 9; v++) appeared[v] = 0;
}

void TRY(int k){
    for(int v = 0; v <= 9; v++){
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
    init();
    ans = 0;
    TRY(0);
}

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N;
        solve();
        cout << ans << endl;
    }
}
