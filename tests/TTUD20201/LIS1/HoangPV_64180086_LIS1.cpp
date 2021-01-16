#include <bits/stdc++.h>

using namespace std;
const int mx = 2e5;
int T, a[mx], n;
int res = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        map<int, int> m;
        res = 1;

        m[a[1]] = 1;

        for (int i = 2; i <= n; i++)
        {
            m[a[i]] = (m.count(a[i] - 1)) ? (m[a[i] - 1] + 1) : 1;
            res = max(res, m[a[i]]);
        }

        cout << res << endl;
    }
}
