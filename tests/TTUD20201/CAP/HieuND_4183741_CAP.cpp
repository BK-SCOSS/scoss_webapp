#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int n;
int a[MAX];
int m;
int b[MAX];

int main() {
    int T;
    int res = 0;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    res++;
                }
            }
        }
    cout << res;
    }
    return 0;
}