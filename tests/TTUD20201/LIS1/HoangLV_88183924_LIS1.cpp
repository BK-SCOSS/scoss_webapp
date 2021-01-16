#include<bits/stdc++.h>

using namespace std;

const int N= 1e6+1;

int n;
int a[N];
int s[N];

void input(){
    cin >> n;
    for(int i=0; i<n; i++) cin>> a[i];
}

void solve(){
    int ans =0;
    for(int i=0; i< n; i++){
        s[i]=1;
        for(int j =0; j< i; j++){
            if(a[i] - a[j] == 1){
                s[i] = max(s[i], s[j]+1);
            }
        }
        ans = max(ans, s[i]);
    }
    cout << ans << endl;
}

int main(){
    int test;
    cin >> test;
    for(int i=0; i< test; i++){
        input();
        solve();
    }
    return 0;
}