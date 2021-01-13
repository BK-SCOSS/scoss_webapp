#include <bits/stdc++.h>
using namespace std;
int x[6];
int xh[10];
int ans, n;

void solution(){
    int temp = x[0]*1000+x[1]*100+x[2]*10+x[3] + x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
    if(temp == n) ans++;
}

bool check(int v, int k){
    if(xh[v] == 0) return true;
    if(xh[v] == 1) return false;
    if(k == 0 && v == 0) return false;
    if(k == 2 && v == 0) return false;
    return true;
}

void TRY(int k){
    for(int v = 0; v <= 9; ++v){
        if(check(v,k)){
                x[k] = v;
                xh[v] = 1;
                if(k == 6){
                solution();
                }else{
                    TRY(k+1);
                }   
                xh[v] = 0;
            }
        }
    }

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        ans = 0;
        for(int i = 0; i <= 9; i++){
            xh[i] = 0;
        }
        TRY(0);
        cout << ans << endl;
    }
}