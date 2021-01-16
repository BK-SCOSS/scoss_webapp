#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int n, m;
int a[MAX], b[MAX];
int T;
int rs;
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];
}

void solve(){
    cin >> T;
    for(int k = 1; k <= T; k++){
        rs = 0;
        input();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i] == b[j]){
                    rs++;
                    continue;
                }
            }
        }
        cout << rs << endl;
    }
}

int main(){
    solve();
    return 0;
}
