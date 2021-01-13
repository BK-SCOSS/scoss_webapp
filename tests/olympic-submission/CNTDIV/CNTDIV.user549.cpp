#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    unsigned long long int T, N, Q, i, j;
    cin >> Q;
    unsigned long long int counts[Q];
    for (i = 0; i < Q; i++) {
        cin >> N;
        T = N * (N + 1) * (N + 2);
        counts[i] = 0;
        for (j = 2; j < T; j++) 
            if (T % j != 0 && (T * T) % j == 0) {
                counts[i]++;
        }
    }
    for (i = 0; i < Q; i++) {
        cout << counts[i] << endl;
    }
}