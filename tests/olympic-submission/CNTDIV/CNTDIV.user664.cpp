#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define max 1000005
long long q, n;
void solve()
{
    unsigned long long i, a, s = 0;
    a = n * (n + 1) * (n + 2);
    for (i = 2; i <= a; i++)
    {
        if ((a * a) % i == 0 & a % i != 0)
        {
            s++;
        }

    }
    cout << s;
}
void nhap()
{
    cin >> n;
}
int main()
{
    cin >> q;
    for (long long i = 1; i <= q; ++i)
    {
        nhap();
        solve();
    }
    return 0;
}