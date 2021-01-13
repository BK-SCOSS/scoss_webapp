#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int cnt = 0;

int X[7];

int value(){
    return 1000*X[0] + 100*X[1] + 10*X[2] + X[3] + 10000*X[2] + 1000*X[4] + 100*X[5] + 10*X[6] + X[3];
}

int check(int v, int k){
    if((k == 0 || k == 2) && v == 0) return 0;
    for(int i = 0; i < k; i++){
        if(X[i] == v) return 0;
    }
    return 1;
}

int Try(int k){
    for(int i = 0; i <= 9; i++){
        if(check(i, k)){
            X[k] = i;
            if(k == 6) {
                if(value() == n) cnt++;
            }
            else Try(k+1);
        }
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        Try(0);
        cout << cnt << endl;
        cnt = 0;
    }

}
