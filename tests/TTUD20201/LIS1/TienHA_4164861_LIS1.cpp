#include<bits/stdc++.h>
using namespace std;
int T,n,ans, tmp;
map<int, int> M;
long long a[100007], v;

int main(){
//    ios_base:: sync_with_stdio(0);
//    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    cin >> T;
    for(int k = 0; k < T; k++) {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        M[a[0]] = 1;
        for(int i = 0; i < n; i++) {
            M[a[i]] = M[a[i]-1] + 1;
        }
        for(pair<int, int> i : M) ans = max(ans, i.second);

        cout << ans << endl;
    }
}
