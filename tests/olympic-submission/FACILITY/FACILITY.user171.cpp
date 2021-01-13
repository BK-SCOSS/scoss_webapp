#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

long long f[800007];

void capnhat(int x,long long y)
{
    for(;x<=100002;x+=x&-x)
        f[x]=max(f[x],y);
}

long long kq(int x)
{
    long long ans=0;
    for(;x>=1;x-=x&-x)
    {
        ans=max(ans,f[x]);
    }

    return ans;
}

typedef pair<int,int> ii;

typedef pair<int,ii> iii;

iii s[600009];

int n,k;


int main()
{
   // freopen("A.INP","r",stdin);
   // freopen("A.OUT","w",stdout);


    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>s[i].fi>>s[i].se.fi>>s[i].se.se;

    sort(s+1,s+1+n);

    long long ans=0;

    for(int i=1;i<=n;i++)
    {
        long long hh=kq(s[i].fi);

        ans=max(ans,hh+s[i].se.se);
        if(kq(s[i].fi+s[i].se.fi+k)<hh+s[i].se.se)
        capnhat(s[i].fi+s[i].se.fi+k,hh+s[i].se.se);
    }

    cout<<ans;
}
