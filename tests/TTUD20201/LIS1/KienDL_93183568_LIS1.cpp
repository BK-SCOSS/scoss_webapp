#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;
int n;
int a[MAX];
map<int, int> S;
int ans;
int T;
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

    }
}

void solve(){
    cin >> T;
    for(int k = 1; k <= T; k++){
        input();
        ans = 0;

        for(int i = 1; i <= n;i++){
            S[a[i]] = 1;
            S[a[i]] = max(S[a[i]-1]+1, S[a[i]]);
            ans = max(ans, S[a[i]]);
        }

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
