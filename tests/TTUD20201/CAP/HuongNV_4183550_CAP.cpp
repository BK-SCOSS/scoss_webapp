#include<bits/stdc++.h>
using namespace std;
int main(){
   int test;
   cin>>test;
   while(test--){
       int dem=0;
       int n1;
       cin>>n1;
       long long x[n1];
       for(int i=1;i<=n1;i++){
           cin>>x[i];
       }
       int n2;
       cin>>n2;
       long long y[n2];
       for(int i=1;i<=n2;i++){
          cin>>y[i];
       }
       for(int i=1;i<=n1;i++){
          for(int j=1;j<=n2;j++){
             if(x[i]==y[j]) dem++;
             continue;
          }
       }
       cout<<dem<<endl;
   }
   return 0;
}
