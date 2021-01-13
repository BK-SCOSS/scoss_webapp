#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e9 + 100;
const int maxn = 1e6 + 100;

struct node {
    int s, d, r;
};

int n, k;
long long f[maxn], res;
node a[maxn];

bool cmp (node a, node b)
{
    if (a.s < b.s) return true;
    return false;
}

int main ()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].d >> a[i].r;
    }

    sort (a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i].r;
        for (int j = 1; j <= i - 1; j++)
        if (a[j].s + a[j].d + k <= a[i].s)
        {
            f[i] = max (f[i], a[i].r + f[j]);
        }
        if (f[i] > res) res = f[i];
    }

    cout << res;
}

