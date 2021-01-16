#include<bits/stdc++.h>
using namespace std;

const int Max = 101;
int n, m, x;
vector<int> a, b;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(find(a.begin(), a.end(), x) == a.end()) a.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        if(find(b.begin(), b.end(), x) == b.end()) b.push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(b[j] == a[i]) ans++;
        }
    }
    cout << ans << endl;
    a.clear();
    b.clear();
}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
