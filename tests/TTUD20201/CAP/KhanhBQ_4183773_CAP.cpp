#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n;
        set<int> a;
        for(int i = 0; i < n; ++i){
            int u; cin >> u;
            a.insert(u);
        }
        cin >> m;
        set<int> b;
        for(int i = 0; i < m; ++i){
            int p; cin >> p;
            b.insert(p);
        }

        int cnt = 0;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < m; ++j){
        //         if(a[i] == b[j]) cnt++;
        //     }
        // }
        for (auto i = a.begin(); i != a.end(); ++i) {
            if (b.find(*i) != b.end()) {
                cnt++;
            }
         }
        cout << cnt << "\n";
    }
}