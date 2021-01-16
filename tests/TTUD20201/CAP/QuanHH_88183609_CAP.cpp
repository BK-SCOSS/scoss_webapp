#include <bits/stdc++.h>

using namespace std;
int t, n, m;

int main(){
    cin >> t;
    while(t--){
        int ans = 0;
        vector<int> a, b;
        set<int> s;
        cin >> n;
        int tmp;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            a.push_back(tmp);
        } 
        cin >> m;
        for (int i = 0; i < m; ++i){
            cin >> tmp;
            b.push_back(tmp);
        }
        for (int i = 0; i < n; ++i){
            if (find(b.begin(), b.end(), a[i]) != b.end()) s.insert(a[i]);
        }
        cout << s.size() << endl;
    }
}