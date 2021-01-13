#include <bits/stdc++.h>
using namespace std;

int X[7];//X[0] = H, X[1] = U, X[2] = S, X[3] = T, X[4] = O, X[5] = I, X[6] = C;
int appeared[10];
unsigned long long ans;
int n;

void solution(unsigned long long N){
    int T = X[0]*1000 + X[1]*100 + X[2]*10 + X[3] + X[2]*10000 + X[4]*1000 + X[5]*100 + X[6]*10 + X[3];
    if(T==N){
        ans++;
    }
}

void init(){
    for(int v=0; v<=9; v++) appeared[v] = 0;
}

void TRY(int k, unsigned long long N){
    for(int v=0; v<=9; v++){
        if(appeared[v]==0){
            X[k] = v;
            appeared[v] = 1;
            if(k==6){
                solution(N);
            }
            else{
                TRY(k+1, N);
            }
            appeared[v]=0;
        }
    }
}

void solve(unsigned long long N){
    init();
    ans = 0;
    TRY(0, N);
    cout << ans << endl;
}

int main(){
    cin >> n;
    unsigned long long A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        solve(A[i]);
    }
}
