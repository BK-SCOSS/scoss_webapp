#include <iostream>
#include <set>


using namespace std;

int n, m;
set<long long> a, b;
int result[11];

void solve(int i) {
    for (const auto &x : a) {
        if (b.find(x) != b.end()) {
            result[i]++;
        }
    }
}

int main() {
    int T;
    long long tmp;
    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            a.insert(tmp);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            b.insert(tmp);
        }
        solve(k);
        a.clear();
        b.clear();
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
