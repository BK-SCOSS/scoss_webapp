#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<ll>
//#define st first
//#define nd second
//#define rd third
#define sps <<" "<<
#define sp <<" "
#define el <<"\n"

struct tripll
{
    ll st;
    ll nd;
    ll rd;
    bool operator< (const tripll &p)
    {
        if(st==p.st)
        {
            if(nd==p.nd) return rd<p.rd;
            else return nd<p.nd;
        }
        else return st<p.st;
    }
};

int binsea(vector<tripll> &dat,int k,int be)
{
    if(dat[dat.size()-1].st<k) return -1;
    if(dat[be].st>k) return be;
    int x=dat.size()-be+1;
    for(int jump=x/2;jump>=1;jump/=2)
        while(be+jump<dat.size()&&dat[be+jump].st<=k) be+=jump;
    be++;
    if(be>=dat.size()) return -1;
    else return be;
}

int main()
{
    int n,k;cin>>n>>k;
    vector<tripll> dat(n);
    for(int i=0;i<n;i++) cin>>dat[i].st>>dat[i].nd>>dat[i].rd;
    for(int i=0;i<n;i++) dat[i].nd+=dat[i].st+k-1;
    sort(dat.begin(),dat.end());
/*
    for(int i=0;i<=12;i++)
    {
        for(int j=0;j<=4;j++)
        {
            cout<<binsea(dat,i,j) sp;
        }
        cout el;
    }*/

//    cout<<binsea(dat,dat[n-3].nd,n-2) el;
    vll dp(n,0);
    dp[n-1]=dat[n-1].rd;
    for(int i=n-2;i>=0;i--)
    {
        int t=binsea(dat,dat[i].nd,i+1);
        if(t==-1)  dp[i]=max(dat[i].rd,dp[i+1]);
        else dp[i]=max(dat[i].rd+dp[t],dp[i+1]);
    }
    cout<<dp[0];
//    for(int i=0;i<n;i++) cout<<dp[i] el;
}
