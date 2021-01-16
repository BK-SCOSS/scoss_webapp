#include <bits/stdc++.h>

using namespace std;
int test;
vector<int > a(100002);
map<int, int> tmp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> test;
    while (test--)
    {
        int n;
        tmp.clear();
        // int a[n];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxx = 0;
        tmp[a[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            int t = a[i];
            if (tmp.count(t - 1))
            {
               tmp[t] = tmp[t -1] + 1;
               maxx = max(maxx,tmp[t]);
            }
            else
            {
                tmp[t] = 1;
                // tmp.insert(make_pair(tmp[t],1));
                maxx = max(maxx , tmp[t]);
            }
            // cout << i << "   " << tmp[a[i]] << endl;
        }
        cout << maxx << endl;
    }
}