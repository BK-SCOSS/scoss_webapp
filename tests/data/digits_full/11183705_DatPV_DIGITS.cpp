#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

long a[1000000];
int f[10];
long n,t,kq,c;

void inkq()
{
    c= a[1]*1000 + a[2]*100 + a[3]*10 + a[4]
    + a[3]*10000 +a[5]*1000 + a[6]*100 + a[7]*10 +a[4];
    
    if (c==n) kq++;
}

void TRY(int x)
{
    int st;
    st=0;
    if (x==1) st=1;
    if (x==3) st=1;

    for (int v=st; v<=9; v++)
    if (f[v]==0)
    {
        a[x]=v;
        f[v]=1;
        if (x==7) inkq();
        else TRY(x+1);
        f[v]=0;

    }
    
}

int main()
{
    cin>>t;
       
    for (int i=1;i<=t;i++)
    {
        cin>>n;
        kq=0;
        for (int i=0; i<=9; i++) f[i]=0;
        TRY(1);
        cout<<kq<<endl;
       
    }

}