#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[7] = {};
int b[10] = {};
int T[2];
int cnt = 0;

void dem(int k)
{
    if (k == 7) {
        int so1 = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[6];
        int so2 = 10000 * a[2] + 1000 * a[3] + 100 * a[4] + 10 * a[5] + a[6];
        if (so1 + so2 == n) {cnt++;}

        return;
    }
    for (int i=0; i<10; i++) {
        if (i==0 && k==0) continue;
        if (i==0 && k==2) continue;

        if (b[i] == 1) continue;

        a[k] = i;
        b[i] = 1;
        dem(k+1);
        b[i] = 0;
    }
}

int main()
{
    int t;

    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 != 0) {
            cout << 0 << endl;
            continue;
        }
        memset(b, 0, 10);
        dem(0);

        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
