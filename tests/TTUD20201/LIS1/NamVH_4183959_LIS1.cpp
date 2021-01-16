#include<bits/stdc++.h>
#define ull long long

using namespace std;


ull T;
ull a[1005][1005];
ull result[1005][1005];

ull lis(ull i, ull testcase) {
    for (ull j = 1; j < i; j++) {
        if ((a[testcase][j] + 1) == a[testcase][i] && result[testcase][i] <= result[testcase][j]) {
            result[testcase][i] = result[testcase][j] + 1;
        }
    }
    return result[testcase][i];
}

int main() {
    cin >> T;
    for (ull i=1; i<= T; i++) {
        cin >> a[i][0];
        for (ull j=1;j<=a[i][0]; j++) {
            cin >> a[i][j];
        }
    }

    for (ull i=1; i<= T; i++) {
        result[i][1] = 1;
        ull res = 1;
        for(ull j = 1; j <= a[i][0]; j++){
            if (res < lis(j, i)){
                res = lis(j, i);
            }
        }
        cout << res << endl;
    }
}
