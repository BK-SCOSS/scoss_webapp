#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, L, s, t;
    cin >> n >> L >> s >> t;
    int q = 3 * n + 1;
    int table[q][q][L + 1];
    for (int i = 1; i < q; i++) {
        for (int j = 1; j < q; j++) {
            if ( i == j) {
                table[i][j][0]= 1;}
            else table[i][j][0] = 0;
        }
    }
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j < q; j++) {
            for (int k = 1; k < q; k++) {
                if (k % 3 == 1) {
                    if (k == 1) {
                        table[j][k][i] = table[j][k + 1][i -1] + table[j][k + 2][i-1] + table[j][q - 1][i - 1];
                    }
                    else table[j][k][i] = table[j][k - 1][i - 1] + table[j][k + 1][i -1] + table[j][k + 2][i - 1];}
                if (k % 3 == 0) {
                    if (k == q - 1) {table[j][k][i] = table[j][k - 2][i - 1] + table[j][1][i - 1];}
                    else table[j][k][i] = table[j][k - 2][i - 1] + table[j][k + 1][i - 1];
                }
                if (k % 3 == 2) {
                    table[j][k][i] = table[j][k-1][i - 1];
                }
            }
        }
    }

    cout << table[s][t][L];

    return 0;
}