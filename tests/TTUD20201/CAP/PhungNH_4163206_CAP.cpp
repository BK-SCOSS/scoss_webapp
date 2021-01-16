#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;

int T;
int m,n;
long long a[MAX];
long long b[MAX];
int result;
long long temp[MAX];

void input(){
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cin >> m;
    for(int j = 0;j < m;j++) {
        cin >> b[j];
    }
}
void solve() {
    for(int i = 0; i < n; i++) {
        bool veri = false;
        for(int k = 0; k < result; k++) {
            if(a[i] == temp[k]) {
                veri = true;
                break;
            }
        }
        if(veri == false) {
            for(int v = 0; v < m; v++) {
                if(a[i] == b[v]) {
                    temp[result] = a[i];
                    result++;
                    break;
                }
            }
        }
    }
    cout << result << endl;
}


int main(){
    cin >> T;
    for(int k = 0; k < T; k++) {
        input();
        result = 0;
        solve();
    }
}