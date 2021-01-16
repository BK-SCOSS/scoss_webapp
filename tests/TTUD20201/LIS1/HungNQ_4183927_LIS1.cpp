#include <bits/stdc++.h>

using namespace std;
int T, n, m, tg, ans;
vector<long> a(10000);

int main() {
    cin >> T;

    for (int z = 0; z < T; z++) {
        cin >> n;
        a.clear();
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n-1; i++) {
            int pre = a[i], sum = 1; 

            for (int j = i+1; j < n; j++) {
                if (a[j] == pre + 1) {
                    pre = a[j];
                    sum++;
                }
            }

            ans = max(sum, ans);
        }

        cout << ans << endl;
    }

    return 0;
}