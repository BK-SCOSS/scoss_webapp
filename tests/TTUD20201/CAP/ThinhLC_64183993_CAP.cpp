#include <bits/stdc++.h>
using namespace std;

int a[100], b[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int T;
    int n, m, res;
    cin >> T;
    for(int i = 0; i < T; i++) {
        res = 0;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> b[j];
        }

        sort(b, b + m);
        for (int j = 0; j < n; j++) {
            int head = 0, finish = m - 1;
            int mid;
            while (head <= finish) {
                mid = (head + finish) / 2;
                if (a[j] == b[mid]) {
                    res++;
                    break;
                } else if (a[j] < b[mid]) {
                    while (b[mid - 1] == b[mid]) {
                        mid--;
                    }
                    finish = mid - 1;
                } else {
                    while (b[mid + 1] == b[mid]) {
                        mid++;
                    }
                    head = mid + 1;
                }
            }
        }

        cout << res << endl;
    }
}
