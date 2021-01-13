#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[7], n, res, mark[15];

void TRY(int k) {
    for (int i = 0; i < 10; ++i) {
        if ((k == 0 || k == 2) & i == 0)
            continue;
        if (!mark[i]) {
            a[k] = i;
            mark[i] = 1;
            if (k == 6) {
                int tong = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] + 
                    a[2] * 10000 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[3];
                if (tong == n) res++;
            } 
            else TRY(k+1);
            mark[i] = 0;
        }
    } 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        res = 0;
        for (int i = 0; i < 10; ++i) mark[i] = 0;
        if (n > 110000) {
            printf("0\n");
            continue;
        }
        TRY(0);
        printf("%d\n", res);
    }
    return 0;
}