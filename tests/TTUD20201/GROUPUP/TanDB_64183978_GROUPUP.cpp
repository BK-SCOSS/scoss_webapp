#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int res = 0;
        while (n > 1)
        {
            int k = 0, t = 0;
            for (int i = 1; i < n; i += 2)
            {
                k++;
                b[k] = a[i] + a[i + 1];
            }

            if (n % 2 == 1)
            {
                k++;
                b[k] = a[n];
            }
            n = k;
            for (int i = 1; i <= n; i++)
            {
                a[i] = b[i];
                t = max(t, a[i]);
            }
            res += t;
        }
        cout << res;
    }
    return 0;
}