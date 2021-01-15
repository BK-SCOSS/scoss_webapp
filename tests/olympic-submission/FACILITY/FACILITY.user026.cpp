/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 1000007
#define Task "FACILITY"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, k, d[maxn], minn = maxC;
pair <pii, int> a[maxn], b[maxn];
long long ans = 0, f[maxn], res[maxn];

void in()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
        a[i].F.S = a[i].F.F + a[i].F.S - 1;
        ans = max(ans, 1ll*a[i].S);
        minn = min(minn, a[i].F.S);
    }
}

void Backtrack(int id)
{
    if (id > n) {
        long long res = 0, cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (!d[i]) continue;
            if (!cur) {
                cur = a[i].F.S + k + 1;
                res += a[i].S;
            } else {
                if (a[i].F.F >= cur) {
                    cur = a[i].F.S + k + 1;
                    res += a[i].S;
                } else return;
            }
        }
        ans = max(ans, res);
        return;
    }
    for (int i = 0; i <= 1; ++i) {
        d[id] = i;
        Backtrack(id+1);
    }
}

bool compare(pair <pii, int> p, pair <pii, int> q)
{
    if (p.F.F != q.F.F) return p.F.F < q.F.F;
    return p.S > q.S;
}

void solve()
{
    sort(a+1, a+n+1, compare);
    for (int i = 1; i <= n; ++i) {
        b[i] = mp(mp(a[i].F.S, a[i].F.F), i);
    }
    sort(b+1, b+n+1, compare);
    if (n <= 10) {
        Backtrack(1);
        cout << ans;
    } else {
        sort(a+1, a+n+1, compare);
        for (int i = 1; i <= n; ++i) {
            b[i] = mp(mp(a[i].F.S, a[i].F.F), i);
        }
        sort(b+1, b+n+1, compare);
        f[1] = 1ll*a[1].S;
        res[1] = f[1];
        for (int i = 2; i <= n; ++i) {
            if (a[i].F.F-k-1 < minn) {
                f[i] = 1ll*a[i].S;
                res[i] = max(res[i-1], f[i]);
                continue;
            }
            int po = lower_bound(b+1, b+n+1, mp(mp(a[i].F.F-k-1, 1), 0)) - b;
            if (b[po].F.F > a[i].F.F-k-1) po--;
            f[i] = res[b[po].S] + 1ll*a[i].S;
            res[i] = max(res[i-1], f[i]);
            ans = max(ans, f[i]);
        }
        cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    //freopen(Task".INP", "r", stdin);
    //freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
