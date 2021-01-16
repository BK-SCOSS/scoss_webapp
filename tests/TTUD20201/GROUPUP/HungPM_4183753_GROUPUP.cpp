#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int T, a, n, ans = 0;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    //freopen("text.inp", "r", stdin);
    cin >> T;
    while (T--){
        cin >> n;
        while (n--){
            cin >> a;
            v.push_back(a);
        }
        while (v.size() != 1){
            if (v.size()%2 == 1){
                v.push_back(0);
            }
            vector<int> v1;
            int maxx = 0;
            for (int i = 0; i < v.size() - 1; i+= 2){
                int tmp = v[i] + v[i+1];
                maxx = max(tmp, maxx);
                v1.push_back(tmp);
            }
            v = v1;
            ans+= maxx;
        }
        cout << ans << endl;
    }
}

