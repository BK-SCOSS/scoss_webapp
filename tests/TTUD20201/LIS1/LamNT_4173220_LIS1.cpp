#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, res;
    unsigned long long a[100000], s[100000];
    cin >> t;
    for (int i = 0; i< t; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> a[j]; 
        };
        s[1] = 1;
        res = s[1];
        for (int j = 2; j <= n; j++) {
            s[j] = 1;
            for (int k = 1; k <= j-1; k++ ) {
                if((a[j] - a[k]) == 1) {
                    if (s[j] < s[k] +1) {
                        s[j] = s[k] +1;
                    };
                };  
            }
            if (s[j] > res) {res = s[j];};
        }
    cout << res << endl;;
    }
}