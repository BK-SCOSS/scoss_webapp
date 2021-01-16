#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
vector<long long> vec;
void solution(long long n, long long a[], long long maxs)
{
    long long maxx = 0;
    long long t = n / 2;
    for (long long i = 1; i <= n / 2; i++)
    {
        a[i] = a[2 * i - 1] + a[2 * i];
        maxx = max(maxx, a[i]);
    }
    if (n % 2 != 0)
    {
        a[n / 2 + 1] = a[n];
        t++;
    }
    maxs = maxs + maxx;
    if (n == 2)
    {
        vec.push_back(maxs);
    }
    else
    {
        solution(t, a, maxs);
    }
}
void input()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        long long a[n + 10];
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        solution(n, a, 0);
    }
}
int main()
{
    input();
    for (long long x : vec)
    {
        cout << x << endl;
    }
    return 0;
}
