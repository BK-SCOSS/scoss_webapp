#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define int long long
#define NMAX 2000006
#define xx first
#define yy second

int n,k,kq,f[3*NMAX],cnt;
pair<int,int> b[NMAX];

struct dh
{
    int s,e,d,r;
}a[NMAX];

void enter()
{
    scanf("%lld %lld",&n,&k);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%lld %lld %lld",&a[i].s,&a[i].d,&a[i].r);
        a[i].d+=k;
        a[i].e = a[i].s + a[i].d -1;
    }
}

void anhxa()
{
    for(int i=1 ; i<=n ; i++)
    {
        b[i].xx = a[i].s;
        b[i].yy = i;
        b[i+n].xx = a[i].e;
        b[i+n].yy= i+n;
    }
    sort(b+1,b+2*n+1);
    cnt = 0;
    for(int i=1 ; i<=2*n ; i++)
    {
        if (b[i].xx!=b[i-1].xx) cnt++;
        if (b[i].yy <=n)
            a[ b[i].yy ].s = cnt;
        else
            a[ b[i].yy-n].e = cnt;
    }
}


void update(int node,int l,int r,int p,int val)
{
    if(p<l || r<p) return;
    if (l==r)
    {
        f[node] = max(f[node],val);
        return;
    }
    int mid = (l+r)/2;
    update(node*2 , l , mid , p ,val);
    update(node*2+1,mid+1, r, p ,val);
    f[node] = max(f[node*2],f[node*2+1]);
}

int query(int node,int l,int r,int i,int j)
{
    if (r<i || j<l) return 0;
    if (i<=l && r<=j) return f[node];
    int mid = (l+r)/2;
    int x1 = query(node*2, l , mid , i , j);
    int x2 = query(node*2+1,mid+1, r , i,j);
    return max(x1,x2);
}

void solve()
{
    anhxa();
    sort(a+1,a+1+n,[](dh u,dh v)
         {
             return u.e<v.e;
         }
    );

    int kq = 0;
    for(int i=1 ; i<=n ; i++)
    {
        int x = a[i].s - 1;
        int tmp = 0;
        if (x>0) tmp = query(1,1,cnt,1,x);
        int y = a[i].r + tmp;
        update(1,1,cnt,a[i].e,y);
        kq = max(kq,y);
    }
    printf("%lld",kq);
}

main()
{
    //freopen("a.inp","r",stdin);
    enter();
    solve();
}
