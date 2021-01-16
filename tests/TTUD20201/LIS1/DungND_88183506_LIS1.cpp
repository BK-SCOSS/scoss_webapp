#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dem = 0;
// vector<int> a;

long long a[1000];
int mem[1000]={};
// memset(mem, -1, sizeof(mem));

int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] +1== a[i])
        {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // a.clear();
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            a[j] = x;
            mem[j] = -1;
        }
        int mx = 0;
        lis(n-1);
        for (int k = 0; k < n; k++)
        {
            mx = max(mx, mem[k]);
        }
        cout<<mx;
    }
    return 0;
}