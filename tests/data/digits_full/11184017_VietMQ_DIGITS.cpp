#include<bits/stdc++.h>

using namespace std;

int x[7]; // H U S T S O I C T
int appear[10];
int N, ans = 0;

bool check(int v, int k)
{
    if(appear[v]) return false;
    if(k == 0 && v == 0) return false;
    if(k == 2 && v == 0) return false;
    return true;
}

void solution()
{
    int K = x[0]*1000 + x[1]*100 + x[2]*10+ x[3] +
            x[2]*10000 + x[4]*1000+ x[5]*100 + x[6]*10 + x[3];
    if(K == N){
        ans++;
    }
}

void TRY(int k)
{
    for(int v = 0; v <= 9; v++){
        if(check(v, k)){
            x[k] = v;
            appear[v] = 1;
            if(k == 6){
                solution();
            }
            else{
                TRY(k+1);
            }
            appear[v] = 0;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i <= 9; i++) appear[i] = 0;
        ans = 0;
        TRY(0);
        cout << ans << endl;
    }
}
