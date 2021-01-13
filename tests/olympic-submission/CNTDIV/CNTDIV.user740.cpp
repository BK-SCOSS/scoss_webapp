#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e9 + 100;
const int maxn = 1e5 + 100;

void process()
{
    long long n, Count = 0, a, b;
    cin >> n;
    a = n * (n + 1) * (n + 2);
    b = a * a;
    for (int i = 4; i <= a - 1; i++)
    if ((a % i != 0) && (b % i == 0))
    {
        Count++;
    }
    cout << Count << endl;
}

int main ()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        process();
    }
}
