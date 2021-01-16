#include<bits/stdc++.h>

using namespace std;

int T, a[101], b[101];

int main(){
    cin>>T;
    for(int k=1; k<=T; k++){
        int n, m, ans=0;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1, a+1+n);
        cin>>m;
        for(int i=1; i<=m; i++)
            cin>>b[i];
        sort(b+1, b+1+m);
        a[0]=-1;
        b[0]=-1;
        for(int i=1; i<=n; i++){
            if(a[i] != a[i-1]){
                int t = a[i];
                for(int j=1; j<=m; j++)
                    if(b[j] == t and b[j] != b[j-1])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
