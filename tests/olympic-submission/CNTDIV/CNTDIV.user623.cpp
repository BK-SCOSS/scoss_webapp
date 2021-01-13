#include<bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    unsigned long long a[q];
    unsigned long long t[q];
    vector<long long> res(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
        t[i] = a[i] * (a[i] + 1) * (a[i] + 2);
    }
    for (int i = 0; i < q; i++) {
        for (int j = 3; j < t[i]; j++) {
            if (t[i] % j != 0 && (t[i] * t[i]) % j == 0) res[i] += 1; 
        }
    }
    for (auto i: res) cout<< i << "\n";
    return 0;
}