#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], amem[100005], res = 0;
map<int, int> mapmem;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        res = 0;
        cin >> n;
        memset(a, 0, sizeof a);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            
        }
        // amem[0] = 1;
        int bestj = 0;
        for (int i = 0; i < n; ++i)
        {
            mapmem[a[i]] = 1;
            auto search = mapmem.find(a[i]-1);
            if (search != mapmem.end()){
                mapmem[a[i]] = search->second + 1;
            }
            res = max(res, mapmem[a[i]]);
        }
        cout << res;
    }

    return 0;
}