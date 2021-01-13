#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        uint64_t a, b;
        cin >> a >> b;
        uint64_t c = a % 10 + b % 10;
        uint64_t d = c % 10;
        uint64_t e = a / 10 + b / 10 + c / 10;
        if (e) cout << e;
        cout << d << '\n';
    }
    return 0;
}