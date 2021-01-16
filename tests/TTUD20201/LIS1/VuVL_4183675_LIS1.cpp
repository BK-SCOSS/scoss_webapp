//
// Created by Zbook 15 G3 on 1/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a[100009];
int main() {
    int T;

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <=n; i++) {
            cin >> a[i];
        }


        int maxS = 1;

        for (int i = 1; i <= n; i ++) {
            int count = 1;
            int tam = a[i];
            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[i]) continue;
                if (a[j] == tam + 1) {
                    count ++;
                    tam = a[j];
                }
            }

            maxS = max(count, maxS);
        }
        cout << maxS;
    }
    return 0;
}
