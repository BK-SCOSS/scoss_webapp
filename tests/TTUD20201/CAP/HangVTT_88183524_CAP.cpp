#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<int> a;
int main()
{
    int t;
    cin >> t;

    int n, m;
    int *b;
    int temp;
    int cnt = 0;

    while (t--) {
        cin >> n;

        for (int i=0; i<n; i++) {
            cin >> temp;
            a.insert(temp);
        }

        cin >> m;
        b = new int[m];
        for (int i=0; i<m; i++) {
            cin >> b[i];
            if (a.find(b[i]) != a.end()) ++cnt;
        }

        delete []b;
    }

    cout << cnt;

    return 0;
}
