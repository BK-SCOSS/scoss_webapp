#include <bits/stdc++.h>

using namespace std;

int t, n, res;

int x[10];

bool used[10];

int calc() {
    return x[1] * 1000 + x[2] * 10010 + x[3] * 100 + x[4] * 2 + x[5] * 1000 + x[6] * 100 + x[7] * 10;
}

void TRY(int i) {
    int st = (i > 2 ? 0 : 1);
    for (int j = st; j <= 9; ++j) {
        if (used[j]) continue;
        used[j] = 1;
        x[i] = j;
        if (i == 7) {
            res += (calc() == n);
        } else {
            if (calc() <= n) TRY(i + 1);
        }
        used[j] = 0;
        x[i] = 0;
    }
}

int main() {
    cin >> t;
    while (t --> 0) {
        cin >> n;
        res = 0;
        TRY(1);
        cout << res << "\n";
    }
}
