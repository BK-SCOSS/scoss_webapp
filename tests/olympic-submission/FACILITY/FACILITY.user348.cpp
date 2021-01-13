#include<bits/stdc++.h>
using namespace std;

const int maxn=(int)2e6;
int n,m;
long long k,f[maxn];
vector<long long> v;
struct X
{
    long long s,f,r;
}a[maxn];

bool cmp(X u,X v)
{
    if(u.s==v.s)return u.f<v.f;
    return u.s<v.s;
}

struct Y
{
    int l,r;
    long long val,lazy;
}tree[maxn*4];

void BuildTree(int id,int le,int ri)
{
    tree[id].l=le;
    tree[id].r=ri;

    if(le==ri)
    {
        tree[id].val=0;
        tree[id].lazy=0;
        return;
    }

    int mid=(le+ri)/2;
    BuildTree(id*2,le,mid);
    BuildTree(id*2+1,mid+1,ri);
}

void Lazy(int id)
{
    long long t=tree[id].lazy;

    tree[id*2].val=max(tree[id*2].val,t);
    tree[id*2].lazy=max(tree[id*2].lazy,t);

    tree[id*2+1].val=max(tree[id*2+1].val,t);
    tree[id*2+1].lazy=max(tree[id*2+1].lazy,t);

    tree[id].lazy=0;
}

void Up(int id,int le,int ri,long long va)
{
    if(tree[id].r<le || tree[id].l>ri)return;

    if(tree[id].l>=le && tree[id].r<=ri)
    {
        tree[id].val=max(tree[id].val,va);
        tree[id].lazy=max(tree[id].lazy,va);
        return;
    }

    Lazy(id);
    Up(id*2,le,ri,va);
    Up(id*2+1,le,ri,va);
    tree[id].val=max(tree[id*2].val,tree[id*2+1].val);
}

long long Get(int id,int le,int ri)
{
    if(tree[id].r<le || tree[id].l>ri)return 0;

    if(tree[id].l>=le && tree[id].r<=ri)
        return tree[id].val;

    Lazy(id);
    return max(Get(id*2,le,ri),Get(id*2+1,le,ri));
}

int main()
{
    cin>>n>>k;

    for(int i=1;i<=n;++i)
    {
        cin>>a[i].s>>a[i].f>>a[i].r;
        a[i].f=a[i].s+a[i].f-1+k;
        v.push_back(a[i].f);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    m=v.size();

    BuildTree(1,1,m);
    sort(a+1,a+n+1,cmp);
    long long ans=0;
    int pos=0;

    for(int i=1;i<=n;++i)
    {
        int low=lower_bound(v.begin(),v.end(),a[i].f)-v.begin();
        long long ansi=a[i].r;
        if(a[i].s>v[0])
        {
            while(a[i].s >= v[pos])++pos;

            ansi+=Get(1,1,pos);
        }

        Up(1,low+1,m,ansi);

        ans=max(ans,ansi);
    }

    cout<<ans;
}
