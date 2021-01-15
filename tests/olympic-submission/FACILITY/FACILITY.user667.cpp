#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back
#define s first.first
#define d first.second
#define r second

using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ll> iii;
const int N = 1e6 + 2;
int n, k;
ii b[2 * N];
iii a[N];
ll res, tree[2 * N];

void update(int u, ll x)
{
    while(u <= 2 * N - 4)
    {
        tree[u] = max(tree[u], x);
        u += u & (-u);
    }
}

ll get(int u)
{
    ll t = 0;
    while(u > 0)
    {
        t = max(t, tree[u]);
        u -= u & (-u);
    }
    return t;
}

void inp()
{
    scanf("%d %d", &n, &k);
    fti(i, 1, n) scanf("%d %d %lld", &a[i].s, &a[i].d, &a[i].r);
}

void proc()
{
    int cnt = 0;
    fti(i, 1, n) {
        b[++ cnt] = ii(a[i].s, i * 2 - 1);
        b[++ cnt] = ii(a[i].s + a[i].d + k, i * 2);
    }
    sort(b + 1, b + cnt + 1);
    int pos = 0;
    fti(i, 1, cnt) {
        if(b[i].first != b[i - 1].first) ++ pos;
        if(b[i].second % 2) a[(b[i].second + 1) / 2].s = pos;
        else a[b[i].second / 2].d = pos;
    }
    ll S;
    sort(a + 1, a + n + 1);
    fti(i, 1, n) {
        S = get(a[i].s) + a[i].r;
        update(a[i].d, S);
        //cout << S << "\n";
        res = max(res, S);
    }
    printf("%lld\n", res);
}

int main()
{
    inp();
    proc();
}
