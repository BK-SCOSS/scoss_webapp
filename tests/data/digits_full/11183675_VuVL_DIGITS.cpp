//
// Created by Zbook 15 G3 on 11/28/2020.
//

#include <bits/stdc++.h>
using namespace std;

int test;
long long a;


int main() {
    cin >> test;

    while (test--) {
        cin >> a;
        int count = 0;
        for(int i = 1000; i <= 999; i ++) {
            cout << i;
            for(int j = 10000; j <= 99999; j ++) {
                int S = ((i % 1000) % 100) / 10;
                int T = ((i % 1000) % 100) % 10;
                cout << i;
                if(S != (j / 10000)) {
                    continue;
                }
                if (T != (((i % 10000) % 1000) % 100) % 10) {
                    continue;
                }

                if(i + j == a) {
                    count ++;
                }

            }
        }
    }

    return 0;
}