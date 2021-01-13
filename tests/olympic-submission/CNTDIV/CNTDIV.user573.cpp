#include <iostream>
#include <unordered_map> 
#include <cmath>

using namespace std;

void solve() {
    int q = 0; cin >> q;
    unsigned long long int n = 0;

    for (int i = 0; i < q; i++) {
        cin >> n;
        n = n * (n + 1) * (n + 2);
        unordered_map<int, int> p;
        for (int i = 2; i <= sqrt(n); ++i) {
            while (n % i == 0) {
                ++p[i];
                n = n / i;
            }
        }
        if (n > 2)
            ++p[n];
        int s1 = 1, s2 = 1;

        for (auto x : p) {
            if (x.first < n) {
                s1 *= 2 * x.second + 1;
                s2 *= x.second + 1;
            }
        }
        cout << s1 - s2 << "\n";
    }
}

int main() {
    solve();
    return 0;
}