#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int a[100001];

int main() {
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long kq = 0;
        while (n > 1) {
            long long Max = 0;
            for (int i = 2; i <= n; i += 2) {
                Max = max(Max, 1ll * a[i] + a[i - 1]);
                a[i / 2] = a[i] + a[i - 1];
            }
            if (n % 2 ==1) a[(n + 1) / 2] = a[n];
            n = (n + 1) / 2;
            kq += Max;
        }
        cout << kq << endl;
    }
}