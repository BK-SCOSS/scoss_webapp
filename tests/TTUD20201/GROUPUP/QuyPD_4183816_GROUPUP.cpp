#include <bits/stdc++.h>

using namespace std;

int t, n, x, y, rs, cnt, ans;
queue<int> q;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            q.push(x);
        }
        cnt = 0;
        rs = 0;
        ans = 0;
        while (!q.empty()) {
            if (n == 1) {
                q.pop();
                break;
            }
            x = q.front();
            q.pop();
            ++cnt;
            if (cnt == n) {
                cnt = 0;
                n = n / 2 + 1;
                q.push(x);
                ans += rs;
                continue;
            }
            y = q.front();
            q.pop();
            ++cnt;
            rs = max(rs, x + y);
            q.push(x+y);
            if (cnt == n) {
                cnt = 0;
                n = n / 2;
                ans += rs;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
