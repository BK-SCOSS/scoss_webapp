#include<bits/stdc++.h>

using namespace std;

int n, a[100001], f[1000001], T;

int main(){
    cin>>T;
    for(int k=1; k<=T; k++){
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<=1000000; i++) f[i] = 0;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            cnt = max (cnt, a[i]);
        }
        if(cnt<=1000000){
            for(int i=1; i<=n; i++)
                f[a[i]] =  f[a[i]-1]+1;
            for(int i=1; i<=1000000; i++)
                ans=max(ans,f[i]);
            cout<<ans<<endl;
        }
        else{
            for(int i=1; i<=n; i++) f[i] = 1;
            for(int i=2; i<=n; i++)
                for(int j=1;j<i;j++)
                    if(a[i] == a[j]+1)f[i]=max(f[i],f[j]+1);
            for(int i=1; i<=n; i++)
                ans=max(ans,f[i]);
            cout<<ans<<endl;
        }
    }
}
