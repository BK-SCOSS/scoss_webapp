#include <bits/stdc++.h>
using namespace std;

//khaibao
int i,j,n,k;
int a[1000020],b[1000020],c[1000020],maxx[1000020];
int kq=0;

int sapxep(int l, int r){
    int i,j,x,y;
    i=l; j=r; x=a[(i+j)/2];
    do {
        while (a[i]<x){
            i++;
        }
        while (a[j]>x){
            j--;
        }
        if (i<=j){
            y=a[i];
            a[i]=a[j];
            a[j]=y;
            y=b[i];
            b[i]=b[j];
            b[j]=y;
            y=c[i];
            c[i]=c[j];
            c[j]=y;
            i++;
            j--;
        }
    } while (i<=j);
    if (l<j){
        sapxep(l,j);
    }
    if (i<r){
        sapxep(i,r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    sapxep(0,n-1);
    for (i=0;i<n;i++){
        maxx[i]=c[i];
        for (j=0;j<i;j++){
            if (a[i]>(a[j]+b[j]-1+k)){
                maxx[i]=max(maxx[i],maxx[j]+c[i]);
                kq=max(maxx[i],kq);
            }
        }
    }
    cout<<kq;
    return 0;
}