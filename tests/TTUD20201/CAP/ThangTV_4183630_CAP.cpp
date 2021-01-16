#include <bits/stdc++.h>
using namespace std;
bool check(long long a, const long long b[], int n){
    for(int i=1;i<=n;i++){
        if(a==b[i]) return true;
    }
    return false;
}
int main() {
    int n,m,t;
    int dem=0;
    cin>>t;
    while(t>=1){
        t--;
        cin>>n;
        long long a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        long long b[m+1];
        for(int i=1;i<=m;i++){
            cin>>b[i];
            if(check(b[i],a,n)){
                dem++;
            }
        }
    }
    cout<<dem;

}
