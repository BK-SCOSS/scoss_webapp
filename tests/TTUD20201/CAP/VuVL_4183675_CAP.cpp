//
// Created by Zbook 15 G3 on 1/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a[10009];
int b[10009];
int main() {
    int T;

    cin >> T;
    while (T--) {
        int n,m;
        cin >> n;
        for(int i = 1; i <=n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for(int i = 1; i <=m; i++) {
            cin >> b[i];
        }

        int count = 0;
        for(int i  = 1; i <= n; i++) {
            for(int j = 1; j <=m; j++) {
                if (a[i] == b[j]) {
                    count++;
                }
            }
        }

        cout << count;
    }
    return 0;
}