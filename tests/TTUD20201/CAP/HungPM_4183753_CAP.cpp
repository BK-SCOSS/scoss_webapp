#include <bits/stdc++.h>
using namespace std;
const int N = 15625001;
int T, n, a, ans = 0;
unsigned long long v1[N], v2[N];
set<int> s;
int main(){
    ios::sync_with_stdio(false);
    //freopen("text.inp", "r", stdin);
    cin >> T;
    while (T--){
        cin >> n;
        while (n--){
            cin >> a;
            int t = a/64;
            s.insert(t);
            v1[t] = v1[t]| (unsigned long long )pow(2,a%64);
        }
        cin >> n;
        while (n--){
            cin >> a;
            int t = a/64;
            s.insert(t);
            v2[t] = v2[t]| (unsigned long long )pow(2,a%64);
        }
        for (auto i : s){
            //cout << v1[i] << " " << v2[i] << "\n";
            bitset<64> b(v1[i]&v2[i]);
            //cout << b << "\n";
            ans+= b.count();
        }
        cout << ans << endl;
    }
}

