#include <bits/stdc++.h>
using namespace std;

long long T, n, x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (long long t = 1; t <= T; t++)
    {
        set<long long> A, B, C;
        
        cin >> n;
        for (long long i = 1; i <= n; i++)
        {
            cin >> x;
            A.insert(x);
        }
        
        cin >> n;
        for (long long i = 1; i <= n; i++)
        {
            cin >> x;
            B.insert(x);
        }

        for (long long e : A)
        {
            if (B.count(e))
            {
                C.insert(e);
            }
        }
        cout << C.size() << endl;
    }

    return 0;
}