#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        int a[100005];
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        while(n > 1) {
//            cout << n << endl;
            int MAX = 0;
            if(n % 2 == 0) {
                for(int i = 1; i <= n; i = i+2) {
                    a[i/2+1] = a[i] + a[i+1];
                    MAX = max(MAX, a[i/2+1]);
                }
            } else {
                for(int i = 1; i <= n-2; i = i+2) {
                    a[i/2+1] = a[i] + a[i+1];
                    MAX = max(MAX, a[i/2+1]);
                }
                a[n/2+1] = a[n];
                n++;
            }
            ans += MAX;
//            cout << MAX << endl;
            n /= 2;

        }
        cout << ans << endl;
    }
    return 0;
}
