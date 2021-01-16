#include <bits/stdc++.h>
using namespace std;
int n;
int a[100007];
int b[100007];
long long res = 0;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        // cout << a[i];
    }
}

void solve(){
    while(n!=1){
        int count = 0;
        b[1] = 0;
        for(int i = 1; i <= n; i = i + 2){
            count ++;
            b[count] = a[i] + a[i+1];
            if( i == n){
                b[count] -= a[i+1];
                
            }
            a[count] = b[count];
            // cout << a[count] << "   ";
        }
        int maxb = b[1];
        for(int i = 2; i <= count; i ++){
            maxb = max(maxb, b[i]);
        }
        res = res + maxb;
        n = count;
        // cout << 1 << " aasdfasdf ";
    
    }

};

int main(){
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
        cout << res << endl;
    }
}