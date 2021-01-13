#include <bits/stdc++.h>

using namespace std;

#define LENGHT 100000000
long T;
long a[LENGHT];
bool checkDigit[10] = {false};
int digits[8]; // H, U, S, T, O, I, C
long dem = 0;

void solve(long n) {
    long N;
    N = digits[1]*1000 + digits[2]*100 + digits[3]*10 + digits[4]
        + digits[3]*10000 + digits[5]*1000 + digits[6]*100 + digits[7]*10 + digits[4];
    if (N == n) dem++;
}

bool check(int k, int i) {
    if (k == 1 && i != 0 && !checkDigit[i])
        return true;
    else if (k == 3 && i != 0 && !checkDigit[i])
        return true;
    else if (!checkDigit[i] && k != 1 && k != 3)
        return true;
    else return false;
}

void TRY(int k, long n) {
    for (int i=0; i<10; i++) {
        if (check(k, i)) {
            digits[k] = i;
            checkDigit[i] = true;
            if (k == 7) {
                solve(n);
            } else TRY(k+1, n);

            checkDigit[i] = false;
        }
    }
}

int main() {
    cin >> T;
    for (long i=0; i<T; i++) {
        cin >> a[i];
    }


    for (long i=0; i<T; i++) {
        TRY(1, a[i]);
        cout << dem << endl;
        dem = 0;
    }
}
