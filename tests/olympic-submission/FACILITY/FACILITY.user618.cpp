#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; i++)
#define pll pair<long long,long long>
#define fi first
#define se second
#define maxn 2000006

using namespace std;

int n;
pair <pll, long long> a[maxn];
int b[maxn];

void input()
{
    //freopen("facility.inp", "r", stdin);
    //freopen("facility.out", "w", stdout);
    int k;
    cin >> n >> k;
    fto (i, 1, n) {
        long long x, y, z;
        cin >> x >> y >> z;
        a[i]={{x, x+y-1+k,}, z};
        b[i]=x;
        b[n+i]=x+y-1+k;
    }
}

map <long long, int> x;
long long bit[maxn];

void update (int x, long long y)
{
    while (x<=maxn) {
        bit[x]=max(bit[x], y);
        x+=(x&(-x));
    }
}

long long get (int x)
{
    long long s=0;
    while (x) {
        s=max(s, bit[x]);
        x-=(x&(-x));
    }
    return s;
}

void solve()
{
    sort(b+1, b+1+n*2);
    int j=1;
    x[b[1]]=1;
    fto (i, 2, 2*n) if (b[i]!=b[i-1]) x[b[i]]=++j; else x[b[i]]=j;
    sort(a+1, a+1+n);
    long long res=0;
    sort(a+1, a+1+n);
    fto (i, 1, n) {
        int d=x[a[i].fi.fi]-1;
        int c=x[a[i].fi.se];
        long long s=get(d)+a[i].se;
        res=max(res, s);
        update(c, s);
    }
    cout << res;
}

int main()
{
    input();
    solve();
}
