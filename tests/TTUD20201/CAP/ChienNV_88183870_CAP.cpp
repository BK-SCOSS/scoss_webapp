#include <bits/stdc++.h>

using namespace std;
#define MAX 102

void check(long long a[MAX], int n) {
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0)
            continue;
        for(int j = i+1; j <= n; j++) {
            if(a[j] == 0)
                continue;
            if(a[j] == a[i]) {
                a[j] = 0;
            }
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n, m;
        long long a[MAX], b[MAX];
        int f[MAX][MAX];
        f[0][0] = 0;
        for(int i = 1; i <= n; i++)
            f[i][0] = 0;
        for(int i = 1; i <= m ; i++)
            f[0][i] = 0;

        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++) {
            if(a[i] == 0)
                continue;
            for(int j = i+1; j <= n; j++) {
                if(a[j] == 0)
                    continue;
                if(a[j] == a[i]) {
                    a[j] = 0;
                }
            }
        }

        cin >> m;
        for(int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        for(int i = 1; i <= m; i++) {
            if(b[i] == 0)
                continue;
            for(int j = i+1; j <= m; j++) {
                if(b[j] == 0)
                    continue;
                if(b[j] == b[i]) {
                    b[j] = 0;
                }
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m ; j++) {
                if((a[i] == b[j]) && (a[i]*b[j] != 0)) {
                    ans ++;
//                    f[i][j] = f[i-1][j-1] + 1;
//                }
//                else {
//                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
//                ans = max(ans, f[i][j]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
