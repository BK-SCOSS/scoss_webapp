#include <bits/stdc++.h>
#include <queue>
using namespace std;

int T, n, tmp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> T;
    for (int i = 0; i < T; i++) {
        int res = 0;
        int maxs = 0;
        deque<int> dq;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            dq.push_back(tmp);
        }
        dq.push_back(-1);

        while (dq.size() != 2) {
            int tmp1 = dq.front();
            dq.pop_front();
            if (tmp1 == -1) {
                res += maxs;
                dq.push_back(tmp1);
                continue;
            }
            int tmp2 = dq.front();
            dq.pop_front();
            if (tmp2 == -1) {
                res += maxs;
                dq.push_back(tmp1);
                dq.push_back(tmp2);
                continue;
            }
            maxs = max(maxs, tmp1 + tmp2);
            dq.push_back(tmp1 + tmp2);
        }
        cout << res + maxs;
    }
}
