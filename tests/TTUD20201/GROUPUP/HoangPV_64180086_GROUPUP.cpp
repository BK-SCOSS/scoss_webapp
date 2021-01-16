#include <bits/stdc++.h>

using namespace std;

const long long mx = 2e5;

long long T, n;
long long B[mx], len;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (long long t = 1; t <= T; t++)
    {
        cin >> n;

        for (long long i = 1; i <= n; i++)
        {
            cin >> B[i];
        }
        len = n;
        long long cost = 0;
        while (len > 1)
        {
            long long tmp = 0;
            for (long long i = 1; i <= len; i += 2)
            {
                B[(i + 1) / 2] = B[i];
                if (i + 1 <= len)
                    B[(i + 1) / 2] += B[i + 1];
                tmp = max(tmp, B[(i + 1) / 2]);
            }
            cost += tmp;
            // cout << "COST " << tmp;
            if (len % 2)
            {
                len = len / 2 + 1;
            }
            else
            {
                len = len / 2;
            }
            // cout << "\nLENGTH " << len << endl;
            // for (long long i = 1; i  <= len; i++)
            // {
            //     cout << B[i] << " ";
            // }
        }
        cout << cost << endl;
    }
}