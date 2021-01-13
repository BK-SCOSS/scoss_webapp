#include <iostream>

using namespace std;

int test, count;
long long N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> test;
    while (test--) {
        cin >> N;
        count = 0;
        if (N % 2 == 0) {
            for (int S = 1; S <= 9; S++)
                if (10010 * S <= N)
                    for (int H = 1; H <= 9; H++)
                        if ((10010 * S + 1000 * H <= N) && (S != H))
                            for (int O = 0; O <= 9; O++)
                                if ((10010 * S + 1000 * H + 1000 * O <= N) && (O != S) && (O != H))
                                    for (int U = 0; U <= 9; U++)
                                        if ((10010 * S + 1000 * H + 1000 * O + 100 * U <= N) && (U != H) &&
                                            (U != S) && (U != O))
                                            for (int I = 0; I <= 9; I++)
                                                if ((10010 * S + 1000 * H + 1000 * O + 100 * U + 100 * I <= N) &&
                                                    (I != S) && (I != H) && (I != O) && (I != U))
                                                    for (int C = 0; C <= 9; C++)
                                                        if ((10010 * S + 1000 * H + 1000 * O + 100 * U + 100 * I + 10 * C <= N)
                                                            && (C != S) && (C != H) && (C != O) && (C != U) && (C != I))
                                                            for (int T = 0; T <= 9; T++) {
                                                                if ((10010 * S + 1000 * H + 1000 * O + 100 * U + 100 * I + 10 * C + 2 * T == N)
                                                                    && (T != S) && (T != H) && (T != O) && (T != U) && (T != I) && ( T!= C))
                                                                    count ++;
                                                            }
        }
        cout << count << endl;
    }
    return 0;
}
