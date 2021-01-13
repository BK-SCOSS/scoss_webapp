#include<bits/stdc++.h>
#define int unsigned long long
const int mn=2e6+10;
const int mx1=1e6+10;
using namespace std;
int t;
long long n;
int a[mn],nt[mn],mx;
void era(int n)
{
    for(int i=1;i<=n;i++)nt[i]=i;
    int tmp=sqrt(n);
    for(int i=2;i<=tmp;i++)
    {
        int j=i*i;
        for(int k=j;k<=n;k+=i)
            if(nt[k]==k)
        {
            nt[k]=i;
        }
    }
}
map<int,int> ma;
vector<int> ngt;
void pt(int x)
{
    while(x!=1)
    {
        if(ma[nt[x]]==0)ngt.push_back(nt[x]);
        ma[nt[x]]++;
       // cerr<<nt[x]<<'\n';
        x=x/nt[x];
    }
}
int res=0;
int xx=1;
void Do(int x,int re,int n)
{
    //cout<<re<<'\n';
    long long tmp=1;
    if(x==n){
    if(re<xx && xx%re!=0)
    {
        res++;
      // cout<<re<<'\n';
    }
            return;
    }
    for(int i=0;i<=ma[ngt[x]]*2;i++)
    {
        //cout<<" "<<"ha";
        if(re*tmp>=xx)return;
        Do(x+1,re*tmp,n);
        tmp=tmp*ngt[x];
    }
}
int lam()
{
    Do(0,1,ngt.size());
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    era(mx+2);
    for(int i=1;i<=t;i++)
    {
        res=0;
        ma.clear();
        ngt.clear();
        xx=a[i]*(a[i]+1)*(a[i]+2);
        pt(a[i]);
        pt(a[i]+1);
        pt(a[i]+2);
        cout<<lam()<<'\n';
    }
    return 0;
}
