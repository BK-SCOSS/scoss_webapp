#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n, m;
        int cnt = 0;
        int cp = 1;
        cin >> n;
        int* a = new int[n + 1];
        int* b = new int[m + 1];
        for (int i = 1; i <= n; i++) {
           cin >> a[i];
        }
        sort(a + 1, a + n + 1);

        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        sort(b + 1, b + m + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = cp; j <= m; j++) {
                if (b[j] == a[i]) {
                    cnt++;
                    cp = j;
                    break;
                }
                else if (b[j] > a[i]) {
                    cp = j;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
