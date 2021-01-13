#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
void solve(){
    int n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    ll T = n * (n + 1) * (n + 2);
    for(ll i = 2; i <= sqrt(T); i++){
        if( T % i == 0){
            a.push_back(i);
            b.push_back(i);
            a.push_back(T/i);
            b.push_back(T/i);
        }
    }
    vector<ll> c;
    ll x;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            x = a[i] * b[j];
            if(x < T && T % x) {
                int cnt = 0;
                for(int k = 0; k < c.size(); k++) if(c[k] == x) cnt++;
                if(cnt == 0) c.push_back(x);
            }
        }
    }
    cout << c.size() << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
