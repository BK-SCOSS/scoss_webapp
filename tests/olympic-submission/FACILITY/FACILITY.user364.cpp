#include <bits/stdc++.h>
#define taskname ""
#define int long long
using namespace std;

const int maxn = 1e6;
struct abc
{
    int s, t, r;
};
abc p[maxn + 10];
int f[maxn + 10];
int n, k;

bool cmp(abc a, abc b)
{
    return a.s < b.s;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].s >> p[i].t >> p[i].r;
    for (int i = 1; i <= n; ++i) p[i].t += p[i].s;
    sort(&p[1], &p[n + 1], cmp);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = p[i].r;
        int hold = 0;
        for (int j = 1; j < i; ++j)
            if (p[j].t <= p[i].s - k) hold = max(hold, f[j]);
        f[i] += hold;
        ans = max(ans, f[i]);
    }
    cout << ans;
}
