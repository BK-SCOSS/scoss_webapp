#include<bits/stdc++.h>
using namespace std;

const int maxn=(int)2e6;
int t,n,nt[maxn],po[maxn];

void snt()
{
    for(int i=1;i<=maxn/2;++i)nt[i]=i;

    for(int i=2;i*i<=1000005;++i)
    {
        if(nt[i]==i)
        {
            for(int j=i*i;j<=1000005;j+=i)
                nt[j]=i;
        }
    }
}

void Solve()
{
    cin>>n;
    int m=n+1;
    int k=n+2;

    vector<int>prime;
    while(n!=1)
    {
        ++po[nt[n]];
        if(po[nt[n]]==1)prime.push_back(nt[n]);
        n/=nt[n];
    }

    while(m!=1)
    {
        ++po[nt[m]];
        if(po[nt[m]]==1)prime.push_back(nt[m]);
        m/=nt[m];
    }

    while(k!=1)
    {
        ++po[nt[k]];
        if(po[nt[k]]==1)prime.push_back(nt[k]);
        k/=nt[k];
    }

    int s=1;
    for(int i=0;i<prime.size();++i)
    {
        int val=prime[i];
        s*=(po[val]+1);
    }
    s--;

    int ss=1;
    for(int i=0;i<prime.size();++i)
    {
        int val=prime[i];
        ss*=(po[val]*2+1);
        po[val]=0;
    }
    ss--;
    ss/=2;
    cout<<ss-s<<'\n';
}

int main()
{
    snt();
    cin>>t;
    while(t--)Solve();
}
