#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int a[100001];
int res[100001];

int main() {
    cin >> T;
    while (T) {
        T--;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k = 0;
        while(n > 1) {
            int maximum = 0;
            int i;
            for (i = 1; i < n; i += 2) {
                int s = a[i]+a[i+1];
                a[(i+1)/2] = s;
                maximum = max(maximum, a[(i+1)/2]);
            }
            res[k] = maximum;
            k++;
            if (i == n) {
                a[(i+1)/2] = a[n];
            }
            n = (n+1)/2;
        }
        int result = 0;
        for (int i = 0; i < k; i++) {
            result += res[i];
        }
        cout << result <<endl;
    }
    return 0;
}