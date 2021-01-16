#include <bits/stdc++.h>

using namespace std;
vector<int> t;
vector<int> c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        t.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            t.push_back(tmp);
        }



        int res = 0;
        while (t.size() > 1)
        {
            int size = t.size();
            int h = size / 2;
            int k = size % 2;
            int sum = 0;
            for (int i = 0; i < h; i++)
            {
                int m = t[2 *i] + t[2 *i + 1];
                c.push_back(m);
                sum = max(sum, m);
            }
            if (k == 1)
            {
                c.push_back(t[size - 1]);
            }
            t = c;
            c.clear();
            res += sum;
        }
        cout << res << endl;
    }
}