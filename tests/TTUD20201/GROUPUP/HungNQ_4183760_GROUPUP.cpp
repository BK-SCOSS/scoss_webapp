#include <bits/stdc++.h>

using namespace std;

int T, n;
const int MAX = 1e5 + 1;
long long S = 0;
long long a[MAX];

int main(){
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        S = 0;

        long long value_max = -INT_MAX;

        while ( n > 1){
            int index = 1;
            for (int i = 0; i < n/2; i++){
                a[index++] = a[i * 2 + 1] + a[i * 2 + 2];
                value_max = max(value_max, a[index - 1]);
            }
            if (n % 2 == 0) index--;
            else a[index] = a[n];

            //for (int i = 1; i <= index; i++) cout << a[i] << ' '; cout << endl;
            if (n % 2 != 0) n = n / 2 + 1; else n /= 2;
            S += value_max;
        }
        cout << S << '\n';
    }
}
