#include <bits/stdc++.h>
using namespace std;
unsigned long long a,b,x[25],y[25],c[25];
int t;
int main()
{
    //freopen("ALICEADD.inp","r",stdin);
    //freopen("ALICEADD.out","w",stdout);
   cin>>t;
   while(t--){
   for(int i=1;i<=24;i++) x[i]=y[i]=c[i]=0;
   cin>>a>>b;//cout<<a+b<<endl;
   int m=0;
   while(a){x[++m]=a%10;a/=10;}
   int n=0;
   while(b){y[++n]=b%10;b/=10;}
   int nho=0;
   for(int i=1;i<=max(n,m);i++) c[i]=(x[i]+y[i]+nho)%10,nho=(x[i]+y[i]+nho)/10;
   if(nho) cout<<1;
   for(int i=max(n,m);i>=1;i--)cout<<c[i];
   cout<<endl;
   }
}

