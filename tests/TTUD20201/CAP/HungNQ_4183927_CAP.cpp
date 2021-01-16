#include <bits/stdc++.h>

using namespace std;
set<long> a;
vector<long> b(100);
int T, n, m, tg, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        ans = 0;
        cin >> n;
        a.clear();
        for (int j = 0; j < n; j++) {
            cin >> tg;
            a.insert(tg);
        }

        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

       // for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                auto findb = a.find(b[k]);
                if (findb != a.end()) ans++;
            }
        //}

        cout << ans << endl;
    }    

    return 0;
}