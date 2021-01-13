#include <bits/stdc++.h>
using namespace std;

unsigned long long a, b, c, d;

int main() {
    int test;
    cin >> test;

    while (test--) {
        cin >> a >> b;
        c = a % 10 + b % 10;
        d = a / 10 + b / 10;

        d += c / 10;
        c = c % 10;
        if (d>0) cout << d;
        cout << c << endl;
    }
}
