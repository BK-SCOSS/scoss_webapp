#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dem = 0;

void find_(vector<long long> a, vector<long long> b, int n, int m, int mark[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!mark[j])
            {   
                // cout<<j<<endl;
                if (a[i] == b[j])
                {
                    dem += 1;
                    mark[j] = 1;
                }
            }
        }
    }
}

int main()
{
    int T;
    vector<long long> a, b;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        a.clear();
        b.clear();
        int n, m;
        int mark[100]={};
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            long long x;
            cin >> x;
            b.push_back(x);
        }
        find_(a, b, n, n, mark);
        cout << dem << endl;
    }
}