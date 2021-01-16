#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int t;
int n;
int a[N];
int sum;
int main() {
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int m = n;
        while(m != 1){

            if(m % 2 == 0){
                for(int i = 1; i <= m/2; i++){
                    a[i] = a[2*i] + a[2*i-1];
                }

                int mx = 0;
                for(int i = 1; i <= m/2; i++){
                    mx = max(mx, a[i]);
                }

                sum += mx;
                m = m/2;
            }

            else {
                for(int i = 1; i <= m/2; i++){
                    a[i] = a[2*i] + a[2*i-1];
                }
                a[m/2 + 1] = a[m];

                int mx = 0;
                for(int i = 1; i <= m/2; i++){
                    mx = max(mx, a[i]);
                }

                sum += mx;
                m = m/2 + 1;
            }

        }

        cout << sum << endl;
    }
}
