#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> a(100010);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        map<int, int> m;
        vector<int> mem(100010, 0);
        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            if (m.count(a[i] - 1))
                mem[i] = mem[m[a[i] - 1] - 1] + 1;
            else
                mem[i] = 1;
            m[a[i]] = i + 1;
            res = max(res, mem[i]);
        }
        cout << res << endl;
    }
    return 0;
}