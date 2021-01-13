#include <iostream>
using namespace std;

int N;
int x[10];
bool mark[10];
long long cnt = 0, sum = 0, result[51];

bool check(int k, int v){
    if (mark[v]) return false;
    if (k == 0 && v == 0) return false;
    if (k == 2 && v == 0) return false;
    return true;
}

void solution(){
    sum = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3] +
              x[2] * 10000 + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3];
    //for (int i = 0; i < 6; i++) cout << x[i] << ' '; cout << endl;
    if (sum == N){
        cnt ++;
        //for (int i = 0; i <= 6; i++) cout << x[i] << ' '; cout << endl;
    }
}

void TRY(int k){
    for (int v = 0; v <= 9; v++)
        if (check(k, v)) {
        x[k] = v;
        mark[v] = true;
        if (k == 6) solution();
        else TRY(k + 1);
        mark[v] = false;
    }
}

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        for (int i = 0; i <= 6; i++) mark[i] = false;
        cin >> N;
        cnt = 0;
        sum = 0;
        TRY(0);
        result[t] = cnt;
        //cout << cnt << '\n';
    }
    for (int t = 1; t <= T; t++) cout << result[t] << '\n';
}


