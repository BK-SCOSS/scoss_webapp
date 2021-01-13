#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int n, k;
priority_queue<pair<int, long long>, vector<pair<int, long long> >, greater<pair<int, long long> > > q;

struct data
{
    int s;
    int f;
    int r;
    data() {}
    data(int _s, int _d, int _r) : s(_s), f(_s + _d), r(_r) {}
} a[MAXN];

bool cmp(data foo, data bar)
{
    return foo.s < bar.s;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int s, d, r;
        cin >> s >> d >> r;
        a[i] = data(s, d, r);
    }

    sort(a + 1, a + n + 1, cmp);

    long long maxv = 0, ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        while (!q.empty() && q.top().first <= a[i].s)
        {
            maxv = max(maxv, q.top().second);
            q.pop();
        }
        long long cur = maxv + 1ll * a[i].r;
        ans = max(ans, cur);
        q.push(make_pair((a[i].f + k), cur));
    }

    cout << ans << endl;

    return 0;
}
