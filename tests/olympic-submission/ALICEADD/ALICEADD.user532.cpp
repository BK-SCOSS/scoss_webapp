#include <bits/stdc++.h>
using namespace std;
void solve( unsigned long long a,  unsigned long long b){
    int e,f;
    if((a>10)&&(b>10))
    {
        e=a%10;
        f=b%10;
        if((e+f)/10==0) cout<< a/10+b/10 <<e+f<<endl;
        else cout<<a/10+b/10+1<<(e+f)/10<<endl;
    }
    else
        cout<<a+b<<endl;
}
int main() {
   int n;
   unsigned long long a[10][2];
   cin>>n;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=2;j++) cin>>a[i][j];
   }
   for(int i=1;i<=n;i++) solve(a[i][1],a[i][2]);
}
