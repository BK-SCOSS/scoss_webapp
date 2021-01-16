#include <bits/stdc++.h>

using namespace std;
int T, n, m, dem = 0, tmp;
long long a[101], b[101];


int main() {
    cin >> T;
    dem = 0;
    while (T--) {
        dem = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++)
                if (a[i] == a[j]){
                    a[j] = -1;
                }

        cin >> m;
        for (int i = 1; i <= m; i++) cin >> b[i];

        for (int i = 1; i < m; i++)
            for (int j = i+1; j <= m; j++)
                if (b[i] == b[j]){
                        b[j] = -1;
                }


        for (int i = 1; i <= n; i++)
            if (a[i] > 0) {
                for (int j = 1; j <= m; j++) {
                    if (a[i] == b[j]) dem++;
                }
            }

        cout << dem << endl;
    }
    return 0;
}
