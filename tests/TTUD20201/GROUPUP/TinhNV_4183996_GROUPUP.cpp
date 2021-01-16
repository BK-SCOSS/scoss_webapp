#include<bits/stdc++.h>

using namespace std;

unsigned int t,n;
unsigned long long ans[10];

unsigned long long tongSo(unsigned long long a[],unsigned int n){
    if(n==2) return a[0]+a[1];
    if(n%2==0){
        unsigned long long dapSo=0;
        unsigned long long b[n/2];
        for(unsigned int i=0;i<n/2;i++){
            b[i]=a[2*i]+a[2*i+1];
            if(dapSo<b[i]) dapSo=b[i];
        }
        return dapSo+ tongSo(b,n/2);
    }else{
        unsigned long long dap=0;
        unsigned long long b[n/2+1];
        for(unsigned int i=0;i<n/2;i++){
            b[i]=a[2*i]+a[2*i+1];
            if(dap<b[i]) dap=b[i];
        }
        b[n/2]=a[n-1];
        return dap+ tongSo(b,n/2+1);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(unsigned int i=0;i<t;i++){
        cin>>n;
        unsigned long long a[n];
        for(unsigned int h=0;h<n;h++){
            cin>>a[h];
        }
        //cout<<"ma"<<endl;
        ans[i]=tongSo(a,n);
        //cout<<"tot"<<endl;

    }
    for(unsigned int i=0;i<t;i++) cout<<ans[i]<<endl;
}
