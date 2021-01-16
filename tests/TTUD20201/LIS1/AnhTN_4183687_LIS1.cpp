#include <bits/stdc++.h>
using namespace std;
int T;
long long n, maxcounst = 0;
long long tong[100000];
long long x[1000000];

void input()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
}
void solve()
{
    for (long long i = 1; i <= n; i++)
    {
        long long i_index = i;
        long long counts = 1;
        for (long long j = i; j <= n; j++)
        {
            if (x[j] - x[i_index] == 1)
            {
                i_index = j;
                counts += 1;
            }
        }
        maxcounst = max(maxcounst, counts);
    }
}
int main()
{
    cin >> T;
    for (int k = 1; k <= T; k++)
    {
        input();
        solve();
        tong[k] = maxcounst;
    }
    for (int k = 1; k <= T; k++)
    {
        cout << tong[k] << endl;
    }
}