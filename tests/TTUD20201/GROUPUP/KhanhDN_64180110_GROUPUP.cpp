#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 1e5 + 2;

int T, n, m, g, h, e, f;
vector<int> b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        b.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> e;
            b.push_back(e);
        }
        m = (int)b.size();
        int tmp;
        int res = 0;
        while (m > 1)
        {
            tmp = 0;
            g = m / 2;
            h = m % 2;
            c.clear();
            for (int i = 0; i < (2 * g); i += 2)
            {
                f = b[i] + b[i + 1];
                c.push_back(f);
                tmp = max(tmp, f);
            }
            if (h == 1)
            {
                f = b[m - 1];
                c.push_back(f);
                tmp = max(tmp, f);
            }
            res += tmp;
            b = c;
            m = (int)b.size();
        }
        cout << res << endl;
    }
    return 0;
}