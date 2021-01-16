#include <bits/stdc++.h>

using namespace std;
int n, a[100001];
void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
long long check()
{
    long long s = 0;
    while (n != 1)
    {
        int Max = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            a[i] = a[2 * i -1] + a[2 * i];
            Max = max(Max, a[i]);
        }
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            a[n/2+1] = a[n];
            n = n/2+1;
        }
        Max = max(Max, a[n]);
        s += Max;
    }
    return s ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        Input();
        cout << check();
        cout << endl;
    }
}