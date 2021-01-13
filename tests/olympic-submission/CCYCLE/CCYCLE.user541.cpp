#include <bits/stdc++.h>

using namespace std;

const int base = (int)1e9 + 7;

int n, l, s, t, f[1005][10005];

int cal(int l, int x)
{
    if (l == 0) return x == t;
    if (f[l][x] != -1) return f[l][x];
    int res = 0;
    if (x % 3 == 0)
    {
        res = (res + cal(l - 1, x == 3 * n ? 1 : x + 1)) % base;
        res = (res + cal(l - 1, x - 2)) % base;
    }
    if (x % 3 == 1)
    {
        res = (res + cal(l - 1, x + 1)) % base;
        res = (res + cal(l - 1, x + 2)) % base;
        res = (res + cal(l - 1, x == 1 ? 3 * n : x - 1)) % base;
    }
    if (x % 3 == 2)
    {
        res = (res + cal(l - 1, x - 1)) % base;
    }
    f[l][x] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> s >> t;
    if (l <= 1000)
    {
        memset(f, 255, sizeof(f));
        cout << cal(l, s);
    }
}
