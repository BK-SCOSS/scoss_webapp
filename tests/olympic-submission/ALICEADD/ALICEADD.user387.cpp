#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        uint64_t a, b;
        cin >> a >> b;
        int aa = a % 10;
        int bb = b % 10;
        a /= 10;
        b /= 10;
        uint64_t foo =  a + b + (aa + bb) / 10;
        if (foo) cout << foo;
        cout << (aa + bb) % 10 << endl;
    }
    return 0;
}