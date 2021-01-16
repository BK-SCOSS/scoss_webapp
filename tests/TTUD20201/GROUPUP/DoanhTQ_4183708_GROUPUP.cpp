#include <bits/stdc++.h>

using namespace std;
const int MA = 100005;


long long tim( long long b[], int q) {
    long long ma = 0;
    for(int i = 0; i < q; i++) {
        ma = max(ma, b[i]);
    }
    return ma;
}


int main() {
   int T;
   cin >> T;
   while(T > 0) {
       int n;
        cin >> n;
        long long a[MA];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long tong = 0;

        while(n > 1) {
            long long b[MA];
            int k = n % 2;
            int q = n / 2;
            for ( int i = 0; i < (n-1); i = i + 2) {
                a[i/2] = a[i] + a[i+1];
            }
            long long duong = tim( a, q);
            tong = tong + duong;
            if (k == 1) a[q] = a[n-1];
            n = k+q;
        }

        cout << tong << endl;
        T--;

   }
    return 0;

}