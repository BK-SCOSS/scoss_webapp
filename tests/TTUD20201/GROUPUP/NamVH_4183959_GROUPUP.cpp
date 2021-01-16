#include<bits/stdc++.h>
#define ull long long

using namespace std;

int T;
ull a[1005][1005];
ull result[1005] = {0};


int main() {
    cin >> T;
    for (int i=1; i<= T; i++) {
        cin >> a[i][0];
        for (ull j=1;j<=a[i][0]; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=1; i<= T; i++) {
        while(a[i][0] > 1) {
            ull temp = 0;
            if (a[i][0] % 2 == 0) {
                for (ull j=1; j<= a[i][0]-1; j=j+2) {
                    a[i][j] = a[i][j] + a[i][j+1];
                }
                temp = a[i][1];
                for (ull j=2; j<= a[i][0]/2; j++) {
                    a[i][j] = a[i][j*2-1];
                    temp = max(temp, a[i][j*2-1]);
                }
            } else {
                for (ull j=1; j<= a[i][0] - 2; j=j+2) {
                    a[i][j] = a[i][j] + a[i][j+1];
                }
                temp = a[i][1];
                for (ull j=2; j<= a[i][0]/2+1; j++) {
                    a[i][j] = a[i][j*2-1];

                    if (j != a[i][0]/2+1) {
                        temp = max(temp, a[i][j*2-1]);
                    }
                }
            }

            result[i] = result[i] + temp;
            a[i][0] = a[i][0] % 2 == 0 ? a[i][0] / 2 : a[i][0] / 2 + 1;
        }
    }

    for (int i=1; i<= T; i++) {
        cout << result[i] << endl;
    }
}
