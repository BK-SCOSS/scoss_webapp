#include <bits/stdc++.h>
using namespace std;

int n, m, T;
int a[100];
int b[100];

void init()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i=0; i<m; i++)
    {
        cin >> b[i];
    }
}

int main()
{
    cin >> T;
    for (int i=1; i<=T; i++)
    {
        vector <int> v;
        v.push_back(-1);
        int cnt=0;
        init();
        sort(a, a+n);
        sort(b, b+n);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ((a[i] == b[j]) && (a[i] != v.back()))
                {
                    cnt++;
                    v.push_back(a[i]);
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
}
