#include <bits/stdc++.h>
using namespace std;
# define MAX 100000
int n,a[MAX],f[MAX];
void solve(){
    int maxt=0;
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[j]+1==a[i] && f[j]+1>f[i]) f[i]=f[j]+1;
        }
        maxt=max(maxt,f[i]);
    }
    cout<<maxt<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t>=1){
        t--;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        solve();
    }
}
