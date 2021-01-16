#include <bits/stdc++.h>
using namespace std;

int n, m, T;
set<int> a, b;
int total = 0;

void solve()
{
    for (set<int>::iterator it1 = b.begin(); it1 != b.end(); it1++)
    {
        if (a.find(*it1) != a.end())
        {
            total++;
        }
    }
    cout << total;
    total = 0;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int val1;
        cin >> val1;
        if (a.find(val1) != a.end() && b.find(val1) != b.end())
        {
            total++;
        }
        else
            a.insert(val1);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int val2;
        cin >> val2;
        if (a.find(val2) != a.end() && b.find(val2) != b.end())
        {
            total++;
        }
        else
            b.insert(val2);
    }
    solve();
}

void init()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        input();
    }
}

int main()
{
    init();
    return 0;
}