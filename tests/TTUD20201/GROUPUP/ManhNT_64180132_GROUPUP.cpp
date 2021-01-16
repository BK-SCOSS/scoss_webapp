#include<bits/stdc++.h>
using namespace std;
int a[10001];
long long kq;
void TRY(int a[],int n){
   if(n==1) {


        return;
   }
   if (n%2==0){
    int b[n/2];
    int maxx=0;
    for (int i=0;i<n/2;i++){
      b[i]=a[2*i]+a[2*i+1];

      if (maxx<b[i]) maxx =b[i];

    }
    kq+=maxx;

    TRY(b,n/2);
   }else{
     int b[n/2+1];
     int maxx=0;
     for (int i=0;i<n/2;i++){
      b[i]=a[2*i]+a[2*i+1];

      if (maxx<b[i]) maxx =b[i];

     }
     kq+=maxx;

     b[n/2]=a[n-1];


     TRY(b,n/2+1);
   }



}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int T,n;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        kq=0;
        TRY(a,n);
        cout<<kq;
    }
}
