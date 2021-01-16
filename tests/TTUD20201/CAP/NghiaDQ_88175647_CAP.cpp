#include <bits/stdc++.h>
using namespace std;

int t;
int n;
long arr[100010];

main()
{
    cin >> t;
    vector<int> res;
    while (t--)
    {
        cin >> n;
        int t[n] = {1};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    t[i] = max(t[i], t[j] + 1);
                }
            }
        }
        res.push_back((int)*max_element(t, t + n));
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
