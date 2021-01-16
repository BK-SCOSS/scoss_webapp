#include<bits/stdc++.h>

using namespace std;

long a[200][200];
long b[200][200];
int result[200] = {0};

int main() {
    int T;
    cin >> T;
    for (int i=1; i<= T; i++) {
        cin >> a[i][0];
        for (long j=1;j<=a[i][0]; j++) {
            cin >> a[i][j];
        }

        cin >> b[i][0];
        for (long j=1;j<=b[i][0]; j++) {
            cin >> b[i][j];
        }
    }

    for (int i=1; i<= T; i++) {
        // Check giao
        if (a[i][0] < b[i][0]) {
            for (long j=1;j<=a[i][0]; j++) {
                for (long t=1;t<=b[i][0]; t++) {
                    if (a[i][j] == b[i][t]) {
                        result[i]++;
                        break;
                    }
                }
            }
        } else {
            for (long j=1;j<=b[i][0]; j++) {
                for (long t=1;t<=a[i][0]; t++) {
                    if (b[i][j] == a[i][t]) {
                        result[i]++;
                        break;
                    }
                }
            }
        }
    }

    for (int i=1; i<=T; i++) {
        cout << result[i] << endl;
    }
}
