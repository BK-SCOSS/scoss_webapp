#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int n, a[MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int res = 0;
        cin >> n;
        map<int, int> lis;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (lis.find(a[i] - 1) != lis.end()) {
                lis[a[i]] = lis[a[i] - 1] + 1;
            }
            else {
                lis[a[i]] = 1;
            }
            res = max(res, lis[a[i]]);
        }
        cout << res << "\n";
    }
    return 0;
}