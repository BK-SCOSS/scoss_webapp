#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 200;
int a[N], b[N];
int main()
{
    int T;
    cin >> T;
    set<int> res;
    for(int i = 1; i <= T; i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++)
           {  cin >> a[j];
           res.insert(a[j]);}
        cin >> m;
        for(int j = 1; j <= m; j++)
            {cin >> b[j];
            res.insert(b[j]);
            }
        cout << m + n - res.size() << "\n" ;
    }
}
