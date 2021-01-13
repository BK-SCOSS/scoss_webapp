#include <bits/stdc++.h>
using namespace std;

struct data
{
    long long s, d  ;
    long long r;
};

bool cmp(data a,data b)
{
    return a.d < b.d;
}
long long n,k,vt;
data a[1111111];
long long F[1111111];
long long b[1111111];

long long get_vt(long long x,long long l , long long r)
{
    if ( x < b[l]) return 0;
    if (l==r) return l;
    long long m = (l+r)/2;
    if (x > b[m]) return max( m , get_vt(x,m+1,r) );
    if (x <=b[m]) return get_vt(x,l,m);
}
int main()
{

   // freopen("FACILITY.inp","r",stdin);
  //  freopen("FACILITY.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>k;

    for (long long i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].d>>a[i].r;
        a[i].d = a[i].s + a[i].d + k ;
        F[i] = -1e18 - 200 ;
    }

    sort( a+ 1 , a+1+n , cmp );
    for (long long i=1;i<=n;i++) b[i] = a[i].d;


    F[0] = 0;
    for (long long i=1;i<=n;i++)
    {
        vt = get_vt(a[i].s,1,i);
        F[i] = max( F[vt] + a[i].r , F[i-1] );
    }

    cout<<F[n];

    return 0;
}
