#include <bits/stdc++.h>

using namespace std;

int n, m;
set<long long> a, b, c;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            a.insert(x);
            c.insert(x);
        }
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            b.insert(x);
            c.insert(x);
        }
        cout << a.size() + b.size() - c.size();
    }
    return 0;
}
