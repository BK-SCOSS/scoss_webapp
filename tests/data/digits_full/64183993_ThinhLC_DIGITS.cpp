#include <bits/stdc++.h>

using namespace std;

void Try(int k);

int res, s, N;
int a[7]; // a[0] = T, a[1] = H, a[2] = U, a[3] = S,
          // a[4] = O, a[5] = I, a[6] = C

int main() {
    int Test;
    cin >> Test;
    for (int i = 0; i < Test; i++) {
//        cin >> N;
//        res = 0;
//        a[0] = (N % 10) / 2;
//        s += (1 << a[0]);
//        Try(1);
//        s = 0;
//        a[0] = ((N % 10) + 10) / 2;
//        s += (1 << a[0]);
//        Try(1);
//        cout << res << endl;
        cin >> N;
        s = 0;
        res = 0;
        Try(0);
        cout << res << endl;
    }
}

void Try(int k) {
    for (int i = 0; i <= 9; i++) {
        if ( ((s >> i) & 1) == 0 ) {
            if (k == 1 || k == 3) {
                if (i == 0) {
                    continue;
                }
            }
            a[k] = i;
            s += (1 << a[k]);

            if (k == 6) {
                int sum = a[3]*10000 + (a[1]+a[4])*1000
                          + (a[2]+a[5])*100 + (a[3]+a[6])*10 + 2*a[0];
                if (sum == N) {
                    res++;
                }
            } else {
                Try(k+1);
            }

            s -= (1 << a[k]);
        }
    }
}
