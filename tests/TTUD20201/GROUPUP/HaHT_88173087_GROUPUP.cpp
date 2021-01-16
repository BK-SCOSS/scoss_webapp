#include <iostream>
#include <queue>

using namespace std;
const int NMAX=1e5;
int t, res;
int a[NMAX];

void group(int x){
    res=1;
    int b[NMAX];
    if(x>1){
    for(int i=1; i<=x/2; i=i+2){
        if(i<x/2*2+1){
        a[i]=a[i]+a[i+1];
        res=res+a[i];
    }
    }
    if(int i = x/2*2==x){
    x=x/2;}
    else{x=x*2+1;}
    return group(x);
    }
    else cout << res;



}
int main()
{
    cin >> t;
    for(int k=1;k<=t;k++){

    int n;
    cin >> n;
    for(int i=1; i <=n; i++){
    cin >> a[i] ;
   }
    group(n);
    }
    return 0;

}

