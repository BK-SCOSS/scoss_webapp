#include <bits/stdc++.h>

using namespace std;
int n;
int x[8];
int f;
bool mark[10];
int cnt;
bool check(int v, int k) {
    if(mark[v]) return false;
    if(v == 0) {
        if(k == 1 || k == 3) return false;
    }
    return true;
}
void print() {
    for(int i = 1; i <= 7; i++) cout << x[i] << " ";
    cout << endl;
}
void TRY(int k) {
    for(int v = 0; v <= 9; v++) {
        if(check(v, k)) {
            x[k] = v;
            mark[v] = true;
            if(k == 1) f += 1000*v;
            else if(k == 2) f += 100*v;
            else if(k == 3) f += 10010*v;
            else if(k == 4) f += 2*v;
            else if(k == 5) f += 1000*v;
            else if(k == 6) f += 100*v;
            else f += 10*v;

            if(k == 7) {
                if(f == n) {
                    cnt++;
                    //print();
                }

            }
            else TRY(k+1);
            mark[v] = false;
            if(k == 1) f -= 1000*v;
            else if(k == 2) f -= 100*v;
            else if(k == 3) f -= 10010*v;
            else if(k == 4) f -= 2*v;
            else if(k == 5) f -= 1000*v;
            else if(k == 6) f -= 100*v;
            else f -= 10*v;
        }
    }
}

void solve() {
    for(int i = 0; i < 10; i++) {
        mark[i] = false;
    }
    cnt = 0;
    f = 0;
    TRY(1);
    cout << cnt << endl;
}
int main() {
    int t;
    cin >> t;
    for(;t--;) {
        cin >> n;
        solve();
    }
}
