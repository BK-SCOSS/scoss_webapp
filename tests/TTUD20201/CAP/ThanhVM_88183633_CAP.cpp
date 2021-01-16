#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int n;
int a[105];
int m;

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        set<int> s;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        cin >> m;
        int b[m + 1];
        int res = 0;
        for(int i = 1; i <= m; i++){
            cin >> b[i];
            if (s.find(b[i]) != s.end()) res++;
        }


        cout << res << endl;

    }
    return 0;
}
