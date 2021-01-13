#include <bits/stdc++.h>

using namespace std;
long long q,n,m;
long long a[1000005];
map <long long ,long long > mymap;
long long b[25];
long long c[25];
long long d[25];
long long kq=0;
void tinh(long long gt){
    long long vt=1;
    while (gt!=1){
        ++mymap[a[gt]];
        gt=gt/a[gt];
    }
}
void lap(long long buoc,long long k,long long ok)
{
    if (buoc==m)
    {
        if (ok==1 && k<=n) kq++;
        return;
    }
    long long tam=1;
    for (long long i=0;i<=2*c[buoc+1];i++)
    {
        if (k*tam>n && ok) return;
        if (i>c[buoc+1]) lap(buoc+1,k*tam,1);
        else lap(buoc+1,k*tam,ok);
        tam=tam*b[buoc+1];
    }
}
int main()
{
    for (long long i=2;i<=1005;i++){
        if (a[i]==0){
            for (long long j=i;j*i<=1000000;j++){
                if (a[i*j]==0)
                {
                    a[i*j]=i;
                }
            }
            a[i]=i;
        }
    }
    cin>>q;
    while (q--)
    {
        cin>>n;
        mymap.clear();
        tinh(n);
        tinh(n+1);
        tinh(n+2);
        m=0;
        kq=0;
        for (map<long long, long long>::iterator it=mymap.begin();it!=mymap.end();++it){
            m++;
            b[m]=it->first;
            c[m]=it->second;
        }
        c[m+1]=1;
        c[m+1]=1;
        d[m+1]=1;
        n=n*(n+1)*(n+2);
        lap(0,1,0);
        cout<<kq<<"\n";
    }
    return 0;
}
