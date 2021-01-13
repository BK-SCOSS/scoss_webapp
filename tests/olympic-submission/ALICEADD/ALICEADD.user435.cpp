#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test --) {
        unsigned long long a, b, _a, _b, a_, b_, c_, _c;
        cin >> a >> b;
        a_ = a / 10;
        b_ = b / 10;
        _a = a % 10;
        _b = b % 10;
        c_ = a_ + b_;
        _c = _a + _b;
        
        if(_c >= 10) {
            c_ += 1;
            _c %= 10;
        }
        if(c_ != 0) cout << c_;
        cout << _c << '\n';
    }
    return 0;
}