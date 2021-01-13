#include <bits/stdc++.h>

using namespace std;
unsigned long long t, a, b;
void solve()
{
   unsigned long long s;
    s=a+b;
    cout << s;
}
void nhap()
{
    cin >> a >> b;
}
int main()
{
    cin >> t;
    for (unsigned long long i = 1; i <= t; ++i)
    {
        nhap();
        solve();
    }
    return 0;
}