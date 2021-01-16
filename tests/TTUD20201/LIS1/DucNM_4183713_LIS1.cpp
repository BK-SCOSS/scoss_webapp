#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n;
    cin>>t;
    while(t--){
        int res = 1;
        map<int, int> m;
        map<int, bool> check;
        cin>>n;
        int a[n];
        int b[n]={0};
        for (int i = 0; i<n; i++) {
            cin>>a[i];
            m[a[i]] = 1;
            if (m[a[i]-1]!=1) m[a[i]-1] = 0;
            check[a[i]] = false;
            check[a[i]-1] = false;
        }
        for (int i = 1; i<n; i++) {
            check[a[i]] = true;
            if (check[a[i]-1]) {
                m[a[i]] = m[a[i]-1] + 1;
                res = max(res, m[a[i]]);
            }
        }
        cout<<res<<endl;
    }
}