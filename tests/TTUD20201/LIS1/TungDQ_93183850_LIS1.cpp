#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n,res;
int a[MAX], d[MAX];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    res = 0;
    int x,j;
    int cnt = 1;
    for (int i = 1; i <= n; i++){
        x = a[i] + 1;
        cnt = 1;
        j = i+1;
        while (j <= n){
            if (a[j] == x){
                x++;
                cnt++;
            }
            j++;
        }
        res = max(res, cnt);
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
