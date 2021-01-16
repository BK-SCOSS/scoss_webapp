#include <iostream>

using namespace std;

int main() {
    int n, m, k, ans;
    int a[100005], b[100005];
    cin >> k;
    while (k>0) {
        k--;
        cin >> n;
        ans = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            b[i] = 0;
        }
        for (int i=0; i<n; i++) {
            for (int j=i-1; j >= 0; j--)
                if (a[j] == a[i]-1) {
                    b[i] = b[j] + 1;
                    break;
                }
                else 
                    if (a[j] = a[i]) {
                        b[i] = b[j];
                        break;
                    }
            if (b[i] > ans) ans = b[i];
        }
        cout << ans + 1 << endl;
        // if (ans > 0) cout << ans + 1 << endl;
        // else cout << 0 << endl;
    }
    return 0;
}