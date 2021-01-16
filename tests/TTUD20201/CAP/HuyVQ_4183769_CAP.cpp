#include <bits/stdc++.h>
using namespace std;
list<long long> req;

void solution(list<long long> a, list<long long> b)
{
    long long s = 0;
    for (int x : a)
    {
        for (int y : b)
        {
            if (x == y)
            {
                s++;
            }
        }
    }
    req.push_back(s);
}
void input()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, m;
        list<long long> a;
        list<long long> b;
        bool visited[100];
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        cin >> m;
        for (int v = 0; v < m; v++)
        {
            long long y;
            cin >> y;
            b.push_back(y);
        }
        solution(a, b);
    }
}
int main()
{
    input();
    for (int k : req)
    {
        cout << k << endl;
    }
    return 0;
}