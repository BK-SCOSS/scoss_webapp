#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pob pop_back
int t, n;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            if (s.find(x) != s.end())
                ans++;
        }
        cout << ans << endl;
    

    }

    return 0;
}
