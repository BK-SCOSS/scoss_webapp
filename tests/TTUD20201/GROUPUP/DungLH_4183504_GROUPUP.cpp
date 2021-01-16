#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int b[100000][17];
    int n, k, h, j;
    cin >> k;
    while (k > 0) {
        k--;
        cin >> n;
        for (int i=0; i<n; i++)
            for (j=0; j<16; j++)
                b[i][j] =  0;
        for (int i=1; i<=n; i++) {
            cin >> b[0][i];
            h = i;
            j = 1;            
            while (h > 0) {
                int p = int(pow(2,j));
                if (h / p == 0) break;
                if (h% p == 0) {
                    b[j][h] = b[j-1][h] + b[j-1][h - p/2];
                    b[j][0] ++;
                }
                else 
                    if (i == n) {
                        b[j][h] = b[j-1][h];
                        b[j][0] ++;
                        if (b[j-1][0] % 2 == 0 && j>1) b[j][n] = b[j-1][n] + b[j-1][n/p*p]; 
                    }
                    else break;                                           
                j++;
            }
        }
        // for (int i =0; i<j; i++) {
        //     for (int j=0; j <= n; j++)
        //         cout << b[i][j] << "  ";
        //     cout << endl; }
        int m = int(log2(n));
        int ans = 0, s;
        for (int i = 1; i <= m; i++) {
            int max = 0;
            s = int(pow(2, i));
            for (j = s;j <= n; j = j +s) { 
                if (b[i][j] > max) max = b[i][j];
                // cout << b[i][j] << "  " << max << endl;
            }
            if (b[i-1][0] % 2==0 && b[i][n] > max) max = b[i][n];
            ans += max;
        }      
        // cout << ans << "  " << m << endl;      
        if (n/int(pow(2,m)) > 0 && n % int(pow(2,m)) != 0) ans += b[m][n] + b[m][s];
        cout << ans << endl;
    }
    return 0;
}
