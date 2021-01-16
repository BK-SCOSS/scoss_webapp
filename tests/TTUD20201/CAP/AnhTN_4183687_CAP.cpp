#include <bits/stdc++.h>
using namespace std;
int T;
long long n, m;
int counts = 0, countss[10000];
long long a[10000], b[10000];
bool visiteda[10000], visitedb[10000];
void input()
{
    cin >> n;
    for (long long j = 1; j <= n; j++)
    {
        cin >> a[j];
    }
    cin >> m;
    for (long long j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
}
bool checka(long long v)
{
    return visiteda[v];
}
bool checkb(long long v)
{
    return visitedb[v];
}
void solve()
{
    for (long long i = 1; i <= n; i++)
    {
        if (!visiteda[a[i]])
        {
            for (long long j = 1; j <= m; j++)
            {
                if (a[i] == b[j])
                {
                    if (!visitedb[b[j]])
                    {
                        visitedb[b[j]] = true;
                        counts+=1;
                    }
                    visiteda[a[i]] = true;
                }
            }
        }
    }
}
int main()
{
    cin >> T;
    for (long long i = 1; i <= T; i++)
    {
        input();
        solve();
        countss[i] = counts;
    }
    for (long long i = 1; i <= T; i++)
    {
        cout << countss[i] << endl;
    }
    return 0;
}