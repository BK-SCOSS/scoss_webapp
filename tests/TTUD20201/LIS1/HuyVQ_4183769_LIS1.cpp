#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
vector<long long> ks;
void solution(long long a[], long long n)
{
    long long s[n][n];
    long long maxs = -1;
    long long count[n][n];
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i; j < n; j++)
        {
            if (i == j)
            {
                s[i][j] = 1;
                count[i][j] = a[i];
                maxs = max(maxs, s[i][j]);
            }
            else
            {
                // cout << a[j] << "  " << count[i][j - 1] << "huy" << endl;
                if (a[j] == count[i][j - 1] + 1)
                {
                    s[i][j] = s[i][j - 1] + 1;
                    count[i][j] = a[j];
                }
                else
                {
                    s[i][j] = s[i][j - 1];
                    count[i][j] = count[i][j - 1];
                }
                maxs = max(maxs, s[i][j]);
            }
        }
    }

    // for (long long i = 0; i < n; i++)
    // {
    //     for (long long j = i; j < n; j++)
    //     {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ks.push_back(maxs);
}

void solu(long long n, long long a[])
{
    long long maxs = 0;
    long long x[n];
    long long counts[n];
    bool visited[n];
    for (long long i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (long long i = 0; i < n - 1; i++)
    {
        x[i] = a[i];
        counts[i] = 1;

        if (!visited[i])
        {
            // visited[i] = true;
            for (long long j = i + 1; j < n; j++)
            {
                if (a[j] == x[i] + 1 && !visited[j])
                {
                    x[i] = a[j];
                    counts[i]++;
                    visited[j] = true;
                }
            }
        }
        maxs = max(maxs, counts[i]);
    }

    ks.push_back(maxs);
}
void input()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        long long a[N];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solu(n, a);
    }
}
int main()
{
    input();
    for (long long s : ks)
    {
        cout << s << endl;
    }
    return 0;
}