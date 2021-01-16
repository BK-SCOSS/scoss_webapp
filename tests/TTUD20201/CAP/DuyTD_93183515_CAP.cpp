#include <bits/stdc++.h>
using namespace std;

vector<int> a(110, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int res = 0;
        int n, m;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            for (auto it : a)
            {
                if (it == tmp)
                {
                    res++;
                    break;
                }
            }
        }
        cout << res;
        a.clear();
    }
    return 0;
}
