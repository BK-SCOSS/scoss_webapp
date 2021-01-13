#include <bits/stdc++.h>
using namespace std;

//khaibao
int i,t;
string a,b;
int c[30],d[30];
int kq[30];

void xuli(){
    int j;
    int nho=0;
    // cout<<a.length()<<endl<<b.length()<<endl;
    for (j=a.length()-1;j>=0;j--){
        c[a.length()-j-1]=a[j]-'0';
    }
    for (j=b.length()-1;j>=0;j--){
        d[b.length()-j-1]=b[j]-'0';
    }
    for (j=0;j<=max(a.length(),b.length())-1;j++){
        // cout<<c[j]<<" "<<d[j]<<endl;
        kq[j]=(c[j]+d[j]+nho)%10;
        nho=(c[j]+d[j]+nho)/10;
    }
    if (nho>0){
        cout<<nho;
    }
    for (j=max(a.length(),b.length())-1;j>=0;j--){
        cout<<kq[j];
    }
    cout<<endl;
}

int main(){
    cin>>t;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for (i=1;i<=t;i++){
        cin>>a>>b;
        xuli();
    }
    return 0;
}