#include<bits/stdc++.h>
using namespace std;
int X[10];
int N;bool mark[10];int sum,cnt;
void solution(){
    for(int i = 1; i<=7;i++){
        cout << X[i] <<" " ;
    }cout << endl;
}
bool check(int i,int k){
    if(mark[i]) return false;
    if(k == 1 && i==0) return false;
    if(k == 3 && i == 0) return false;
    return true;
}
void TRY(int k){
    for(int i = 0; i<=9;i++){
        if(check(i,k)){
            X[k] = i;mark[i] = true;
            if(k == 7){
                sum = X[3] * 10000 + (X[1] + X[5]) * 1000 + (X[2] + X[6]) * 100 + (X[3] + X[7]) * 10 + X[4] * 2;
                if(sum == N) cnt++;
            }
            else TRY(k+1);
            mark[i] = false;
        }
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        for(int i = 0;i<=9;i++){
            mark[i] =false;
        }
        cnt = 0;
        cin >>  N;
        if(N > 110000) cout << 0 <<endl;
        else {
            TRY(1);
            cout << cnt << endl;
        }
    }

}
