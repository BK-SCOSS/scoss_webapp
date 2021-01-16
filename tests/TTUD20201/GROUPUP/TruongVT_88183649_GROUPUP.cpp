#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define ll long long
int res = 0;

void solve(int a[], int n) {
    int *b = new int[n];
    if (n == 1) {
        return;
    }
    else {
        for (int i = 0; i < n/2; ++i) {
            b[i] = a[2*i+1] + a[2*i];
        }
        res += *max_element(b, b+n/2);
        if (n % 2 == 1) {
            b[n/2] = a[n-1];
            solve(b, n/2+1);
        } 
        else solve(b, n/2);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a[MAXN];
        res = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(a, n);
        cout << res << "\n";
    }
    return 0;
}