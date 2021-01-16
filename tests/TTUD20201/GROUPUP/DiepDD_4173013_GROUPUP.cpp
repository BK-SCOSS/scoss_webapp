#include <bits/stdc++.h>

using namespace std;

static const int N = 10001;
int t, n;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int tmp;
        queue<int> q1, q2;
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            q1.push(tmp);
        }

        long long res = 0;
        while (q1.size() != 1) {
            int maxE = -1;
            while (!q1.empty()) {
                int k2;
                int k1 = q1.front();
                q1.pop();
                if (!q1.empty()) {
                    k2 = q1.front();
                    q1.pop();
                } else {
                    k2 = 0;
                }
                q2.push(k1+k2);
                maxE = max(maxE, k1+k2);
            }
            res += maxE;
            swap(q1, q2);
        }

        cout << res << endl;
    }
}
