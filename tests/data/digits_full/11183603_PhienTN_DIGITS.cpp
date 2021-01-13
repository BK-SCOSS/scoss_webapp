#include<bits/stdc++.h>
using namespace std;
int n;
int x[8];
bool visited[10];
int res;
bool check(int v, int k){
    if( k == 1 && v == 0){
        return false;
    }
    if(k== 3 && v== 0){
        return false;
    }
    if(visited[v]){
        return false;
    }
    return true;
}
void solution(){
    int T = x[1]*1000 + x[2]*100 + x[3]*10010 + x[4]*2 + x[5]*1000 + x[6]*100+x[7]*10;
    if( T == n){
        res++;
    }
}
void TRY(int k){
    for(int v = 0; v <= 9; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            if(k == 7){
                solution();
            }
            else TRY(k+1);
            visited[v] = false;
        }
    }
}
int main() {
    int sotest;
    cin >> sotest;
    for(int i = 1; i <= sotest; i++){
        res = 0;
        cin >> n;
        for(int j = 0; j <10; j++){
            visited[j] = false;
        }
        TRY(1);
        cout << res << endl;
    }

}
