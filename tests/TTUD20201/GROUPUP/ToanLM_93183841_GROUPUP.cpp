#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, a[MAX];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    int res = 0;
    while (n > 1){
        int c = n%2;
        int ss = 0, t;
        for (int i = 1; i <= n/2; i++){
            t = a[2*i] + a[2*i - 1];
            ss = max(ss,t);
        }
        res += ss;

        // Gop
        int cnt = 1;
        for (int i = 1; i <= n/2; i++){
            t = a[2*i] + a[2*i - 1];
            a[cnt] = t;
            cnt++;
        }
        if (c){
            a[cnt] = a[n];
        }
        n = n/2 + c;
    }
    cout << res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        input();
        solve();
    }
}
