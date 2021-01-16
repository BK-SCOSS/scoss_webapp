#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int T, a, n, ans = 0;
map<int,int> m;
int main(){
    ios::sync_with_stdio(false);
    //freopen("text.inp", "r", stdin);
    cin >> T;
    while (T--){
        cin >> n;
        while (n--){
            cin >> a;
            if (m[a - 1] != 0){
                m[a - 1]++;
                m[a] = max(m[a-1], m[a]);
                m[a-1] = 0;
            }
            else{
                if(m[a] == 0){
                    m[a] = 1;
                }
            }
        }
        for (auto i : m){
            ans = max(ans, i.second);
        }
        cout << ans << endl;
    }
}

