#include <bits/stdc++.h>
using namespace std;

const int MAX = 100003;

int T;
int n;
int a[MAX];

map<int, int> MAP;

void solve() {
    int result = 0;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (MAP.find(t - 1) == MAP.end())
        {
            MAP.insert({t, 1});
        } else
        {
            result = max(result, MAP[t - 1] + 1);
            MAP[t] = max(MAP[t], MAP[t - 1] + 1);
        }
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n;
        MAP.clear();
        solve();
    }
    return 0;
}