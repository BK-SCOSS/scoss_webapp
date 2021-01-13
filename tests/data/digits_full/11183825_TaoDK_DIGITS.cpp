#include<bits/stdc++.h>
using namespace std;
#define MAX 10

int T, N;
int X[MAX];
int mark[MAX];
int result = 0;

bool check(int *X){
    int value =  (X[1] * 1000 + X[2] * 100 + X[3] * 10 + X[4])
     + (X[3] * 10000 + X[5] * 1000 + X[6] * 100 + X[7] * 10 + X[4]);
    if(value != N) return false;
    if(X[1] == 0 || X[3] == 0) return false;
    return true;
}

void TRY(int i, int N){
    if(i > 7){
        if(check(X)){
            result++;
        }
        return;
    }
    for(int v = 0; v <= 9; v++){
        if(!mark[v]){
            X[i] = v;
            mark[v] = 1;
            TRY(i + 1, N);
            mark[v] = 0;
        }
    }
}

void input(){
    cin >> T;
    while(T > 0){
        for(int i = 0; i < MAX; i++){
            mark[i] = 0;
        }
        cin >> N;
        result = 0;
        TRY(1, N);
        cout << result << endl;
        T--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}
