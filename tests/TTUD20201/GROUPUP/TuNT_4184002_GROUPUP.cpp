#include <bits/stdc++.h>
using namespace std;

const int Max = 100005;
int t, n, a[Max];
int res = 0;
int tmp;

int main()
{
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        while(log(n)/log(2) > 0) {
            if(n%2 == 0) {
                n /= 2;
                tmp = 0;
                for(int k = 0; k < n; k++) {
                    a[k] = a[2*k] + a[2*k+1];
                    tmp = max(tmp, a[k]);
                }
                res += tmp;
            } else {
                n = n/2+1;
                tmp = 0;
                for(int k = 0; k < n-1; k++) {
                    a[k] = a[2*k] + a[2*k+1];
                    tmp = max(tmp, a[k]);
                }
                a[n-1] = a[2*(n-1)];
                res += tmp;
            }
        }
        cout << res << endl;
    }
    return 0;
}
