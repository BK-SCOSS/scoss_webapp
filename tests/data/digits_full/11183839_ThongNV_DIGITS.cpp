#include <bitset>
#include <iostream>

using namespace std;

int Solve(int n) {
    int ic, hus, t, k, cnt = 0;
    for (k = 1; k <= 9; ++k) {
        bitset<10> b;
        b.set(k);
        for (t = 1; t <= 9; ++t) {
            bitset<10> b1;
            b1 = b;
            b1.set(t);
            for (ic = 12; ic <= 98; ++ic) {
                bitset<10> c;
                c = b1;
                int res = (n + 62 + k * 100 - 2 * t);
                if (res % 10 != 0) {
                    continue;
                }
                hus = res / 10 - ic;
                if (hus < 100) {
                    continue;
                }
                int tmp;
                tmp = hus;
                while (tmp) {
                    c.set(tmp % 10);
                    tmp /= 10;
                }
                tmp = ic;
                while (tmp) {
                    c.set(tmp % 10);
                    tmp /= 10;
                }

                if (c.count() == 7 && c[0] == 0) {
                    // cout << ic << " " << hus << " " << t << " " << k << "\n";
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << Solve(n);

    return 0;
}