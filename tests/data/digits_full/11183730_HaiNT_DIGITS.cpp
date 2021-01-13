#include <bits/stdc++.h>
using namespace std;

#define  HNT  ios_base::sync_with_stdio(false);  cin.tie(0);

int x[8];
int N, T, cnt = 0;

bool check (int v, int k) {
    for (int i = 1; i < k; i++) {
        if(x[i] == v) return false;
    }
    return true;
}

void TRY (int k) {
    for (int v = 0; v < 10; v++){
        if(v == 0) {
            if (k == 1 || k == 3) continue;
        }
        if (check(v,k)) {
            x[k] = v;
            if (k == 7){
                if((1000*x[1] + 100*x[2] + 10*x[3] + x[4]) +
                        (10000*x[3] + 1000*x[5] + 100*x[6] + 10*x[7] + x[4]) == N)
                   {
                        cnt++;
                   }
            }
            else TRY (k + 1);
        }
    }
}

int main (){
    HNT;
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> N;
        TRY (1);
        cout << cnt << endl;
    }
    return 0;
}


