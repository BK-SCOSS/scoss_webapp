#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, n, m, res = 0;
    cin >> test;
    for (int t = 0; t < test; t++) {
        int cur = -1;
        cin >> n;
        int *arr1 = new int[n];
        for (int i = 0; i < n; i++) cin >> arr1[i];
        cin >> m;
        int *arr2 = new int[m];
        for (int i = 0; i < m; i++) cin >> arr2[i];
        for (int i = 0; i < n; i++)
            if (arr1[i] == cur) continue;
            else {
                cur = arr1[i];
                for (int j = 0; j < m; j++) {
                    if (cur == arr2[j]) {
                        res += 1;
                        break;
                    }
                }
            }
        cout << res << "\n";
    }
    return 0;   
}
