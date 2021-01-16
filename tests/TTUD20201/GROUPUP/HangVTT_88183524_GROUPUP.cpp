#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int *a;

int main()
{
    int t;
    cin >> t;

    int res = 0;
    int max_ = 0;
    int j;

    while (t--) {
        res = 0;

        cin >> n;
        a = new int[n];

        for (int i=0; i<n; i++) cin >> a[i];

        while (n) {
            max_ = 0;
            j = 0;

            if (n == 2) {
                //cout << "0 1: " << a[0] << " " << a[1] << endl;
                res += a[0] + a[1];
                break;
            }
            if (n % 2 == 0) {
                for (int i=0; i<n-1; i += 2) {
                    a[j] = a[i] + a[i+1];
                    max_ = max(max_, a[j]);
                    j++;
                    //cout << "max_: "<<max_ << endl;
                }
                n = j;
                //cout << "n: " << n << endl;
            }
            else {
                for (int i=0; i<n-2; i+=2) {
                    a[j] = a[i] + a[i+1];
                    max_ = max(max_, a[j]);
                    j++;
                    //cout << "max_: "<<max_ << endl;
                }
                a[j] = a[n-1];
                n = j + 1;
                //cout << "n: " << n << endl;
            }
            res += max_;
            //cout << "res: " << res << endl;
        }
        cout << res << endl;
        delete []a;
    }

    return 0;
}
