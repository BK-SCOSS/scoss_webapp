#include<bits/stdc++.h>
using namespace std;
int T, n,m,ans;
long long a[110],b[110], c[110];


int main(){
//    ios_base:: sync_with_stdio(0);
//    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    cin >> T;
    for(int k = 0; k < T; k++) {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        cin >> m;
        for(int i = 0;i < m;i++) cin >> b[i];
        
        ans = 0;
        for(int i = 0; i < n; i++) {
            int ch = 0;
            for(int t = 0; t < ans; t++) {
                if(a[i] == c[t]) {
                    ch = 1;
                    break;
                }
            }
            if(ch == 0) {
                for(int j = 0; j < m; j++) {
                    if(a[i] == b[j]) {
                        c[ans] = a[i];
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
