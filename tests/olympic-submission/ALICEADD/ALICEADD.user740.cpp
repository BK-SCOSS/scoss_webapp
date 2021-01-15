#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e9 + 100;
const int maxn = 1e5 + 100;

int main ()
{
    long double n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long double a, b;
        cin >> a >> b;
        cout << fixed;
        cout << setprecision(0);
        cout << a + b << endl;
    }
}
