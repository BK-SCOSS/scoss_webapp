#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 100;
int a[N], mark[N];
int n;
int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {   int maxx = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mark[i] = 0;
        }
        for(int i = 1; i < n; i++)
        { if(mark[i] != 1)  {

            int d = 1;
            for(int j = i + 1; j <= n; j++) {
            if(a[j] == a[i] + d) {d++;
            mark[j] = 1; }
            maxx=max(maxx,d);
            }
        }
        }
        cout << maxx << "\n";
}
}
