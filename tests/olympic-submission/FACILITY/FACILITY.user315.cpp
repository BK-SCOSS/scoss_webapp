#include    <bits/stdc++.h>
#define     N   int(1e6)+7

using       namespace std;

struct point{
    int bd, kt, cost;
}a[N];

int n, k;
int f[N];

bool cmp(point a, point b){
    return (a.kt < b.kt || (a.kt == b.kt && a.bd < b.bd));
}

void readf()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i].bd >> a[i].kt >> a[i].cost;
}

void solve()
{
    for(int i = 0; i < n; i++) a[i].kt = a[i].bd + a[i].kt - 1 + k;
    sort(a, a + n, cmp);
    f[0] = a[0].cost;
    int res = 0;
    for(int i = 1; i < n; i++){
        f[i] = 0;
        for(int j = 0; j < i; j++)
        if (a[j].kt < a[i].bd) f[i] = max(f[i], a[i].cost + f[j]);
        res = max(res, f[i]);
    }
    cout<<res;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("facility.inp","r",stdin);
    readf();
    solve();
}
