#include <iostream>
using namespace std;

int t, n, m, a[99999999], b[99999999];

int main () {

    cin >> t;

    while(t--) {
        int rev = 0, ma = 0, mb = 0, hx = 0, hy = 0;
        cin >> n;
        for ( int i = 1; i <= n; ++i ) {

            int x; cin >> x;
            if (x == 1000000000) {
                hx += 1;
            } else {
                ma = max(ma, x);
            }
            a[x] += 1;
        }
        cin >> m;
        for ( int i = 1; i <= m; ++i ) {
            int x; cin >> x;
            if (x == 1000000000) {
                hy += 1;
            } else {
                mb = max(mb, x);
            }
            b[x] += 1;
        }
        for ( int i = 1; i <= max(ma, mb); ++i) {
            if (a[i] > 0 && b[i] > 0) {
                rev += 1;
            }
            a[i] = b[i] = 0;
        }
        if (hx > 0 && hy > 0) rev += 1;
        cout << rev << '\n';
    }

    return 0;
}