#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

const int BASE = 10000;
typedef vector <int> BigInt;
BigInt Init(string s) {
    BigInt a; if (s.size() == 0) { a.push_back(0); return a; }
    while (s.size() % 4 != 0) s = '0' + s;
    for (int i = 0; i < (int)s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 10 + (s[i + j] - '0');
        a.insert(a.begin(), value);
    } return a;
}
void Print(const BigInt a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
BigInt operator + (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (size_t i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) {
        c.push_back(carry);
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string sa, sb;
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> sa >> sb;
        BigInt a = Init(sa);
        BigInt b = Init(sb);
        Print(a + b);
    }
    return 0;
}
