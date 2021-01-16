#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(100010);
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        int res;
        while (n != 1)
        {
            vector<int> b(100010);
            int tmp_size;
            if (n % 2 == 0)
            {
                tmp_size = n;
                n = n / 2;
            }
            else
            {
                tmp_size = n - 1;
                n = n / 2 + 1;
                b[n-1] = a[tmp_size];
            }
            int max_pair;
            for (int i = 0; i < tmp_size; i += 2)
            {
                b[i / 2] = a[i] + a[i + 1];
                max_pair = max(max_pair, b[i / 2]);
            }
            a = b;
            res += max_pair;
        }
        cout << res;
    }

    return 0;
}
