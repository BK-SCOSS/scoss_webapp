#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n, m, x;
    while(t--) {
        set<int> s, a, b;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
            a.insert(x);
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> x;
            s.insert(x);
            b.insert(x);
        }

        cout << (a.size() + b.size() - s.size()) << endl;
    }
}
