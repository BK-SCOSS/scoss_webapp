#include <bits/stdc++.h>

using namespace std;

int n, m, T;
int main() {
    //freopen("D:\\input\\1.txt","r",stdin);
    cin >> T;
    while (T--) {

        cin >> n;
        int x;
        set<int> a, b;
        for (int i = 1; i<=n; i++) {
            cin >> x;
            a.insert(x);
        }
        cin >> m;
        for (int i = 1; i<=m; i++) {
            cin >> x;
            b.insert(x);
        }
        int res = 0;
        for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
            int y = *it;
            set<int>::iterator pos = b.find(y);
            if (pos != b.end()) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
