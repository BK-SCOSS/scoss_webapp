#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,k,ma[1000006];
pair<pair<int,int>,int> a[1000006];

int BS(int l,int r,int x)
{
    if(l>r) return l;
    int mid=(l+r)/2;
    if(a[mid].first.first>=x) return BS(l,mid-1,x);
    else return BS(mid+1,r,x);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("FACILITY.inp","r",stdin);
    //freopen("FACILITY.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>a[i].first.first>>x>>a[i].second;
        a[i].first.second=a[i].first.first+k+x;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i].first.first<<" "<<a[i].first.second<<" "<<a[i].second<<'\n';
    }
    ma[n]=a[n].second;
    for(int i=n-1;i>=1;i--)
    {
        int id=BS(i+1,n,a[i].first.second);
        //cout<<i<<" "<<id<<'\n';
        ma[i]=max(ma[i+1],ma[id]+a[i].second);
    }
    cout<<ma[1];
}
