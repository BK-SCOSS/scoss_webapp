#include <bits/stdc++.h>
using namespace std;

//khaibao
int n,q,i,j;
unsigned long long int so,so2;
long long int dem=0;

int main(){
    cin>>q;
    for (i=1;i<=q;i++){
        dem=0;
        cin>>n;
        so=n*(n+1)*(n+2);
        so2=so*so;
        for (j=1;j<sqrt(so2);j++){
            if ((so2%j==0)&&(so%j!=0)){
                dem++;
            }
        }
        cout<<dem<<endl;
    }
}