#include<bits/stdc++.h>
using namespace std;
int test;
int n;
int x[8];//x[0] = h,x[1] = u...
bool visited[11];
int cnt = 0;
bool check(int v, int k){
    if(visited[v]) return false;
    if(k == 1 && v == 0) return false;
    if(k == 3 && v == 0) return false;
    return true;
}
void solution(){
    int sum = x[1]*1000 + x[2]*100 + x[3]*10 + x[4] + x[3]*10000
     + x[5]*1000 + x[6]*100 + x[7]*10+x[4];
     if(sum == n){
        cnt++;
     }
}

void TRY(int k){
    for(int v = 0;v<=9;v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            if(k == 7) solution();
            else TRY(k+1);
            visited[v] = false;
        }
    }
}
void reset(){
    for(int i =0;i<=10;i++){
        visited[i] = false;
    }
}
int main(){
    cin>>test;
    while(test--){
        cin>>n;
        reset();
        cnt = 0;
        TRY(1);
        cout<<cnt<<endl;
    }


}
