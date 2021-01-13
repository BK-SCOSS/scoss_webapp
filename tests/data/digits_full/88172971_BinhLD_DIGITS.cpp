#include <iostream>
#include <bits/stdc++.h>


int N = 0;
int res = 0;
int a[8] = {}; // H, U, S, T, O, I, C (8 pt vi try tu 1)
                // 1, 2, 3, 4, 5, 6, 7
int n = 7;

void input() {
    res = 0;
    std::fill(a, a+n+1, -1);
    std::cin >> N;
}

bool check(int k, int v) {
    for (int i = k - 1; i > 0; i--) {
        if (a[i] == v) {
            return false;
        }
    }
    return true;
}

void solution() {
    // tinh HUST + SOICT
    int current = (a[1]*1000 + a[2]*100 + a[3]*10 + a[4]) + (a[3]*10000 + a[5]*1000 + a[6]*100 + a[7]*10 + a[4]);
    if (current == N) {
        res++;
    }
    return;
}

void TRY(int k) {
    for (int v = 0; v <= 9; v++) {
        if (check(k, v)) {
            a[k] = v;
            if (k == n) {
                solution();
            } else {
                TRY(k+1);
            }
            a[k] = -1;
        }
    }
}

void solve() {
    input();
    TRY(1);
    printf("%d\n", res);
}

int main()
{
    int T = 0;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
