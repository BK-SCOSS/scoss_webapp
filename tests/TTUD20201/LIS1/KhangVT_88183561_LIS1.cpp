#include <iostream>
#define N 10003
using namespace std;

int t, n, a[N];
int d[N][N];

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        for ( int i = 1; i < n + 1; ++i ) {
            cin >> a[i];
        }

        for (int i = 1; i < n + 1; ++i) {
            d[0][i] = 1;
        }
        for (int i = 1; i < n + 1; ++i) {
            for ( int j = 1; j < n + 1; ++j) {
                d[i][j] = max(d[i - 1][j], d[i][j]);
                if (a[i] == a[j] + 1) d[i][j] = max(d[i][j], d[i - 1][j] + 1);
            }
        }

        int rev = 0;
        for (int i = 1; i < n + 1; ++i) {
            rev = max(rev, d[n][i]);
        }
        cout << rev << '\n';
    }
    return 0;
}