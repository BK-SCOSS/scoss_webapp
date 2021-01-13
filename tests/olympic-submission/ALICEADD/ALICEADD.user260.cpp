#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define w(var) cerr << "DEBUG: " << (#var) << " = " << (var) << ";" << endl
#else
#define w(var)
#endif

int main () {
    int t;
    uint64_t a, a1, a2;
    uint64_t b, b1, b2;
    uint64_t c1, c2;

    cin >> t;
    while (t--) {
        cin >> a >> b;

        a1 = a % 10;
        a2 = a / 10;
        b1 = b % 10;
        b2 = b / 10;

        c1 = (a1 + b1) % 10;
        c2 = a2 + b2 + (a1 + b1) / 10;

        if (c2) {
            cout << c2;
        }
        cout << c1 << endl;
    }
}