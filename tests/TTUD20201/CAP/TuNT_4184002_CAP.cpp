#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int t, n, m;
int a[MAX], b[MAX];
int res;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        res = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        sort(a, a+n);
        cin >> m;
        for(int j = 0; j < m; j++)
            cin >> b[j];
        sort(b, b+m);
        for(int j = 0; j < n-1; j++) {
            if(a[j] == a[j+1]) {
                a[j] = 0;
            }
        }
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                if(a[j] == b[k] && a[j] != 0 && b[k] != 0)
                    res++;
        cout << res << endl;
    }
    return 0;
}
