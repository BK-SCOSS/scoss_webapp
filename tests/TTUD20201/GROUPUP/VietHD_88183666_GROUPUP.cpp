#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005];
int res = 0;
void solve(int n)
{
    if (n==1) {
        return;
    }
    int j = 1, maxa = -1;
    for (int i = 1; i < n; i += 2)
    {
        a[j] = a[i] + a[i + 1];
        maxa = max(a[j], maxa);
        j++;
    }
    if (n % 2 != 0)
    {
        maxa = max(maxa, a[n]);
        a[j] = a[n];
        n = n / 2 + 1;
    }
    else
        n = n / 2;
    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << " ";
    // cout << endl;
    res += maxa;
    solve(n);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        res = 0;
        memset(a, 0, sizeof a);
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        solve(n);
        cout << res << endl;
        // int j = 1;
        // cout << n / 2 << endl;
        // for (int i = 1; i < n; i += 2)
        // {
        //     cout << i << " ";
        //     cout << j << endl;
        //     j++;
        // }
        // cout << j << endl;
    }

    return 0;
}