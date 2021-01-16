#include <bits/stdc++.h>

using namespace std;
const int MA = 105;


int main() {
    int T;
    cin >> T;
    while(T > 0) {
        int n, m;
        long long a[MA], b[MA];
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            int check  = 0;
            for (int j = 0; j < k; j++) {
                if (a[j] == t) check++;
       
            }
            if (!check) {
                a[k] = t;
                k++;
            }
        }

        n = k;


         cin >> m;
        int q = 0;
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            int check  = 0;
            for (int j = 0; j < q; j++) {
                if (b[j] == t) check++;

            }
            if (!check) {
                b[q] = t;
                q++;
            }
        }
        m = q;
        


        int tong = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) tong++;
}
            }
        
        cout << tong << endl;
        T--;
    }
    return 0;
}