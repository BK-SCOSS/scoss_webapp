#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int T;
int n, m;
int a[MAX], b[MAX];
int res;

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                res++;
            }
        }
    }
    cout << res << endl;
}
void input(){
    cin >> T;
    while(T > 0){
        res = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> b[i];
        }
        solve();
        T--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    return 0;
}
