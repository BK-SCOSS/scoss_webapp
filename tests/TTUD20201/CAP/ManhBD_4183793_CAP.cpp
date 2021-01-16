#include<bits/stdc++.h>
using namespace std;
int const N = 1000009;
int T;
int n,m;
int a[N],b[N],c[N];
// int count[1000009];
int cnt=0;
// int size =0;
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin  >> m;
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
}
void solve(){
    for(int i=0;i<n;i++){
        // if(n>m){
            for(int j=0;j<m;j++){
                if(a[i]==b[j]) {
                    a[i] = a[i+1];
                    b[j] = b[j+1];
                    cnt++;
                    cout << a[i] << "\n" << b[j] << "" << endl;
                }
                if(a[i]!=b[j]) continue;
            }
    }
}
int main(){
    input();
    solve();
    cout << cnt;
    return 0;
}
