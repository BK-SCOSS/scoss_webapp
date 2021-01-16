#include <bits/stdc++.h>

using namespace std;
const int MA = 100005;


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

        int tong = 1;
        for (int i = 0; i < (n - tong); i++) {
            int dem = 1;
            int k = i;
            for (int j = i+1; j < n; j++) {
                if (a[k] == (a[j] - 1)) {
                    dem ++;
                    k = j;
                }
            }
            tong = max(tong, dem);
        }

        cout << tong << endl;
    return 0;

   }
    

}