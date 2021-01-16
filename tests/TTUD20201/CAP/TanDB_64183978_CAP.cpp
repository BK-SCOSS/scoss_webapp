#include <bits/stdc++.h>
using namespace std;
long long n, m, a[101], b[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> c;
        vector<int> d;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int sizec=0, sized=0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[i - 1])
            {
                c.push_back(a[i]);
                sizec++;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (b[i] != b[i - 1])
            {
                d.push_back(b[i]);
                sized++;
            }
        }
        int j = 0, i = 0, res = 0;
        while (i <sizec && j <sized)
        {
            if (c[i] == d[j])
            {
                res += 1;
                j++;
                i++;
            }
            else
            {
                if (c[i] < d[j])
                {
                    i++;
                }
                else
                    j++;
            }
        }
        cout << res << endl;
    }

    return 0;
}