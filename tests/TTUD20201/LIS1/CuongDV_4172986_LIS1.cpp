#include <bits/stdc++.h>
using namespace std;

int n, T, res, val;
int *a;
map<int, int> m;
int dem = 1;

void solve()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] == a[i] + 1)
            {
                m.insert(pair<int, int>(i, j));
                break;
            }
            // else
            //     m.insert(pair<int, int>(i, 0));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int dem1 = 1;
        int z;
        z = m[i];
        while (z != 0)
        {
            dem1++;
            z = m[z];
        }
        if (dem1 >= dem)
            dem = dem1;
    }
    cout << dem << endl;
}

void input()
{
    cin >> n;
    a = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int val1;
        cin >> val1;
        a[i] = val1;
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