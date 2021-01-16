#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
map<int,int> p;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        p.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int res=0;
        for (int i = 1; i <= n; i++)
        {
            int x=a[i];
            int c=p[x-1]+1;
            p[x]=max(p[x],c);
            res=max(res,p[x]);
        }

        cout << res << endl;
    }
    return 0;
}