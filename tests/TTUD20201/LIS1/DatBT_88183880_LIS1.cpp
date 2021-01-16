#include <bits/stdc++.h>

using namespace std;
long long T, n;
long long a[100001], mem[100001];
bool comp[100001];


int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) mem[i] = 1;
        for (int i = 0; i < n; i++) comp[i] = false;

        mem[0] = 1;
        comp[0] = true;

        for (int i = 1; i < n; i++) {
            if (comp[i] == false) {
                for (int j = 0; j < i; j++) {
                    if (a[i] == a[j] + 1) {
                        mem[i] = mem[j] + 1;
                        comp[i] = true;
                    }
                }
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (mx < mem[i]) mx = mem[i];
        }
        cout << mx;
    }
    return 0;
}
