#include <iostream>

using namespace std;

int main() {
    int n, m, k, ans;
    int a[105], b[105];
    cin >> k;
    while (k > 0) {
        k--;
        ans = 0;
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        cin >> m;
        for (int i=0; i<m; i++) cin >> b[i];
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (a[i] == b[j]) { 
                    ans++;
                    break;
                }
        cout << ans << endl;
    }
    return 0;
}