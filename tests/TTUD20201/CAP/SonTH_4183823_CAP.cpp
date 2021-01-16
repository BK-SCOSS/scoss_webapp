#include <iostream>
#include <queue>
#include <set>
using namespace std;

int T, m, n;
int a[101];
int b[101];
queue<int> Q;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }

        int cc = 0;
        set<int> S;

        for (int i = 1; i <= n; i++)
        {
            S.insert(a[i]);
        }

        for (int i = 1; i <= m; i++)
        {
            if (S.find(b[i]) != S.end())
            {
                cc++;
            }
        }
        Q.push(cc);
    }

    while (!Q.empty())
    {
        int a = Q.front();
        Q.pop();
        cout << a << "\n";
    }
    return 0;
}