#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10],ok[10];
long long n,t;
int res;
void dq(int x){
    
    if(x>=8){
        
        int u = a[1]*1000+a[2]*100+a[3]*10+a[4];
        int v = a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4];
        if(u+v==n) ++res;
        return;    
    }
    for(int i = (x==1||x==3);i<=9;++i){
        if(ok[i]) continue;
        ok[i] =1;
        a[x] =i;
        dq(x+1);
        ok[i]=0;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(ok,0,sizeof(ok));
        res = 0;
        dq(1);
        cout<<res<<endl;
    }
    // system("pause");
    return 0;
}