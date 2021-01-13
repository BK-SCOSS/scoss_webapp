#include <bits/stdc++.h>
using namespace std;

int x[7];
int appeared[10];
int ans, N;
int M; //So lan lap

void solution() {
    int T = x[0]*1000+x[1]*100+x[2]*10+x[3]+x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
    if(T == N) {
        ans++;
    }
}

void init() {
    for(int v = 0; v <=9; v++) appeared[v] = 0;
}

void TRY(int k) {
    for(int v = 0; v<=9; v++) {
        if(appeared[v]==0) {
            if(k == 0 || k == 2)
                if(v == 0) continue;
            x[k] = v;
            appeared[v] = 1;
            if(k == 6) {
                solution();
            } else {
                TRY(k+1);
            }
            appeared[v] = 0;
        }
    }
}

void solve() {
    cin >> N;
    init();
    ans = 0;
    TRY(0);
    cout << ans << endl;
}

int main() {
    cin >> M;
    for (int i = 0; i < M; i++) {
        solve();
    }

    return 0;
}
