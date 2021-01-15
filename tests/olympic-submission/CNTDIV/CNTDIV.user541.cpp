#include <bits/stdc++.h>

using namespace std;


const int maxn = (int)1e6 + 5;

int t, d[maxn], mark[maxn];
vector<long long> div1, div2;
long long m, res, n;
vector<pair<int, int>> v1, v2;


vector<pair<int, int>> prime_div(int n, vector<pair<int, int>> v)
{
    for(int i = 0; i < v.size(); i++)
        mark[v[i].first] = i;
    while (n > 1)
    {
        int x = d[n];
        while (n % x == 0)
        {
            if (mark[x] == -1)
            {
                v.push_back({x, 1});
                mark[x] = v.size() - 1;
            } else v[mark[x]].second++;
            n /= x;
        }
    }
    for(int i = 0; i < v.size(); i++)
        mark[v[i].first] = -1;
    return v;
}

void process(long long x, int i, bool ok)
{
    if (i == v1.size())
    {
        div1.push_back(x);
        if (ok) div2.push_back(x);
        return;
    }
    long long cur = 1;
    for(int j = 0; j <= v1[i].second * 2; j++)
    {
        if (j == 0) process(x, i + 1, ok); else
        {
            if (m / x / cur / v1[i].first > 0) cur *= v1[i].first; else break;
            process(x * cur, i + 1, ok || v1[i].second < j);
        }
    }
}

int count_by_maxVal(long long val, vector<long long> v)
{
    int first = 1;
    int last = v.size();
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (v[mid - 1] <= val) first = mid + 1; else last = mid - 1;
    }
    return first - 1;
}

void process1(long long x, int i, bool ok)
{
    if (i == v2.size())
    {
        if (ok) res += count_by_maxVal(m / x, div1); else res += count_by_maxVal(m / x, div2);
      //  cout << x << " " << res << endl;
        return;
    }
    long long cur = 1;
    for(int j = 0; j <= v2[i].second * 2; j++)
    {
        if (j == 0) process1(x, i + 1, ok); else
        {
            if (m / x / cur / v2[i].first > 0) cur *= v2[i].first; else break;
            process1(x * cur, i + 1, ok || v2[i].second < j);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    for(int i = 2; i < maxn; i++)
    {
        mark[i] = -1;
        if (d[i] == 0)
        {
            d[i] = i;
            long long j = 1ll * i * i;
            while (j < maxn)
            {
                d[j] = i;
                j += i;
            }
        }
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        n++;
        m = n * (n - 1) * (n + 1);
        v1.clear();
        v2.clear();
        v1 = prime_div(n, v1);
        v2 = prime_div(n - 1, v2);
        v2 = prime_div(n + 1, v2);
        while (div1.size() > 0) div1.pop_back();
        while (div2.size() > 0) div2.pop_back();
        process(1, 0, 0);
        sort(div1.begin(), div1.end());
        sort(div2.begin(), div2.end());
        res = 0;
        process1(1, 0, 0);
        cout << res << endl;
    }
}


