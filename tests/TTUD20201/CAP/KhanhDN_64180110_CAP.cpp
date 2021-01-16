#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> a(102), b(102), c, d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    int n, m;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        c.clear();
        c.push_back(a[1]);
        for (int i = 2; i <= n; i++)
        {
            if (a[i] > a[i - 1])
            {
                c.push_back(a[i]);
            }
        }
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> b[j];
        }
        sort(b.begin() + 1, b.begin() + m + 1);
        d.clear();
        d.push_back(b[1]);
        for (int j = 2; j <= m; j++)
        {
            if (b[j] > b[j - 1])
            {
                d.push_back(b[j]);
            }
        }
        int res = 0;
        for (auto x : c)
        {
            for (auto y : d)
            {
                if (x == y)
                {
                    res += 1;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}