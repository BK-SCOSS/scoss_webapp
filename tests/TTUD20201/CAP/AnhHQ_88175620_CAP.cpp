#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
long a1[105], a2[105];

int main()
{
    cin >> t;
    vector<int> res;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }
        sort(a1, a1 + n);
        sort(a2, a2 + m);
        int i = 0, j = 0, r = 0;
        while (i < n && j < m)
        {
            if (a1[i] < a2[j])
            {
                i++;
            }
            else if (a1[i] > a2[j])
            {
                j++;
            }
            else
            {
                r++;
                i++;
                j++;
            }
        }
        res.push_back(r);
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}