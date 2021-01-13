#include<bits/stdc++.h>
#define ff first.first
#define fs first.second
#define s second
#define pp pair<pair<int,int>,int>
const int mn=1e6+6;
using namespace std;
int n,k;
pair<pair<int,int>,int> gt[mn];
bool cmp(pp a,pp b)
{
    return a.fs<b.fs;
    return a.s>b.s;
    return a.ff<b.fs;
}
long long r[mn];
long long res=0;
long long it[mn*4];
int lef[mn*4],rig[mn*4],la[mn];
void built(int x,int l,int r1)
{
    lef[x]=l;rig[x]=r1;
    if(l==r1)
    {
        la[l]=x;
        it[x]=r[l];
        return;
    }
    int mid=(l+r1)/2;
    built(2*x,l,mid);
    built(2*x+1,mid+1,r1);
    it[x]=max(it[x*2],it[2*x+1]);
}
void upd(int x,long long k)
{
     x=la[x];
    it[x]=max(it[x],k);
    x/=2;
    while(x>0)
    {
        it[x]=max(it[2*x],it[2*x+1]);
        x/=2;
    }
    return;
}
long long get(int x,int l,int r)
{
    if(lef[x]>r||rig[x]<l)return 0;
    if(lef[x]>=l&&rig[x]<=r)return it[x];
        long long kq1=get(2*x,l,r);
        long long kq2=get(2*x+1,l,r);
    return max(kq1,kq2);
}
int g[mn];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>gt[i].ff>>gt[i].fs>>gt[i].s;
        gt[i].fs+=gt[i].ff+k-1;
    }
    sort(gt+1,gt+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        r[i]=gt[i].s;
        g[i]=gt[i].fs;
    }
    built(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int l=lower_bound(g+1,g+n+1,gt[i].ff)-g-1;
        //cout<<l<<" ";
        long long k1=get(1,1,l);
        upd(i,k1+gt[i].s);
        r[i]=max(r[i],it[la[i]]);
        res=max(res,r[i]);
    }
   // for(int i=1;i<=n;i++)cout<<r[i]<<" ";
    cout<<res;
    return 0;
}
