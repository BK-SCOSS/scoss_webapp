#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn 1000005
#define ll long long
#define Ntu "FACILITY"
#define int long long

using namespace std;

int n,k;
struct data{int s,d,r;};
data a[maxn];
int f[maxn], b[maxn];
bool cmp(data x,data y) {return (x.s<y.s);}

int ge(int x)
{
    int s=0;
    for(;x>0;x-=x&-x) s=max(s,f[x]);
    return s;
}

void ud(int x,int y)
{
    for(;x<=n;x+=x&-x) f[x]=max(f[x],y);
}

main()
{
    ios_base::sync_with_stdio(0);
    //freopen (Ntu".inp","r",stdin);
    //freopen (Ntu".out","w",stdout);
    cin >> n >> k;
    int z=0,z1;
    fto(i,1,n) cin >> a[i].s >> a[i].d >> a[i].r, b[++z]=a[i].s;
    sort(b+1,b+n+1);
    sort(a+1,a+n+1,cmp);
    int rs=0;
    int y;
    fto(i,1,n)
    {
        z=lower_bound(b,b+n+1,a[i].s)-b;
        y=ge(z)+a[i].r;
        rs=max(rs,y);
        z1=lower_bound(b,b+n+1,a[i].s+a[i].d+k)-b;
        ud(z1,y);
    }
    cout << rs;
    return 0;
}
