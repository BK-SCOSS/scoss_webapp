#include<bits/stdc++.h>

using namespace std;

unsigned int t,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    unsigned int ans[t];
    for(unsigned int i=0;i<t;i++){
        cin>>n;
        unsigned int a[n];
        unsigned int kt[1000000];
        ans[i]=0;
        for(unsigned int h=0;h<n;h++) cin>>a[h];
        for(unsigned int h=0;h<n;h++){
            unsigned int x= a[h];
            kt[x] = kt[x-1] +1;
            ans[i]=ans[i]>kt[x]? ans[i] : kt[x];
        }


    }
    for(unsigned int i=0;i<t;i++) cout<<ans[i]<<endl;

}
