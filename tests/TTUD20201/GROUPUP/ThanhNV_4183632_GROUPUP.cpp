#include<bits/stdc++.h>
#define MAX 100004
using namespace std;
int t,n;
int a[MAX];

int KQ(int n){
    int t=1;
    int res =0;
    for(int i=1;i<=n;i+=2){
        if(i==n) {
            res=max(res, a[i]);
            a[t++]=a[i];
        }
        else {
            a[t]=a[i]+a[i+1];
            res=max(res, a[t++]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;

    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int sum=0;
        while(n>1){
            sum+=KQ(n);
            if(n%2==0)n=n/2;
            else n=n/2+1;
        }

        cout<<sum<<endl;
    }
    return 0;
}
