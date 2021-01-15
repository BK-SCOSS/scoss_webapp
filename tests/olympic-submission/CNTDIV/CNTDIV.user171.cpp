#include<bits/stdc++.h>

using namespace std;

long long fa[1000009],f[1000009],nt[1000009];

void cb()
{
    for(long long i=2;i<=1000001;i++)
    {
        nt[i]=i;
    }

    for(long long i=2;i<=1000001;i++)
    {
        if(nt[i]==i)
        {
            long long j=i;

            while (j<=1000001)
            {

                nt[j]=i;
                j+=i;
            }
        }
    }
}

long long cnt=0;

long long kk()
{

    sort(fa+1,fa+1+cnt);

    long long ans1=1,ans2=1;

        for(long long i=1;i<=cnt;i++)
            if(fa[i]!=fa[i-1])
            ans1*=(f[fa[i]]+1);

         for(long long i=1;i<=cnt;i++)
            if(fa[i]!=fa[i-1])
            ans2*=(f[fa[i]]*2+1);


    for(long long i=1;i<=cnt;i++)
    {
        f[fa[i]]=0;
        fa[i]=0;
    }

    return (ans2+1)/2-ans1;
}

long long lam(long long n)
{
    long long a=n;

    cnt=0;

    while (a!=1)
    {
        long long u=nt[a];

        fa[++cnt]=u;
        while (a%u==0)
        {
            f[u]++;
            a/=u;
        }
    }

    a=n+1;
    while (a!=1)
    {
        long long u=nt[a];

        fa[++cnt]=u;
        while (a%u==0)
        {
            f[u]++;
            a/=u;
        }
    }

    a=n+2;
    while (a!=1)
    {
        long long u=nt[a];

        fa[++cnt]=u;
        while (a%u==0)
        {
            f[u]++;
            a/=u;
        }
    }

    return kk();
}

main()
{
   // freopen("A.INP","r",stdin);
   // freopen("A.OUT","w",stdout);

long long q;    cin>>q;

cb();

    while (q--)
    {
        long long n;cin>>n;

        cout<<lam(n)<<endl;
    }
}
