#include <bits/stdc++.h>
#define x first
#define y second
#define HANH ""
using namespace std;

int n;
long long k, kq[1000005], b[1000005];

struct data
{
    long long u, v, gt;
} a[1000005];

bool cmp(data a, data b){
    if(a.v!=b.v) return a.v<b.v;
    return a.u<=b.u;
}

int main()
{
    //freopen("".inp, "r", stdin);
    //freopen("".out, "w", stdout);
    scanf("%d", &n);
    scanf("%lld", &k);
    for(int i=1; i<=n; ++i){
        scanf("%lld%lld%lld", &a[i].u, &a[i].v, &a[i].gt);
        a[i].v+=a[i].u+k;
    }
    //cout <<endl;
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; ++i){ b[i]=a[i].v; }
    for(int i=1; i<=n; ++i){
        int vt=lower_bound(b+1, b+n+1, a[i].u+1)-b-1;
        //cout <<vt <<endl;
        if(vt>=i) vt=i-1;
        kq[i]=a[i].gt+kq[vt];
        kq[i]=max(kq[i-1], kq[i]);
        //cout <<a[i].u <<" " <<a[i].v <<" " <<kq[i] <<endl;
    }
    printf("%lld", kq[n]);
    return 0;
}
