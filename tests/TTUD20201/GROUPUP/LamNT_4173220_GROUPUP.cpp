#include <bits/stdc++.h>
using namespace std;
unsigned long long a[100000], b[100000];
int t, n;
unsigned long long temp, s;

int main() {
    int m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        m = n;
        s = 0;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        };
        while (m != 1) {
            if (m % 2 == 0) {
                temp = 0;
                for(int j = 0; j<m; j=j+2 ){
                    b[j/2]=a[j]+a[j+1];
                    temp = max(temp, b[j/2]);
                };
                s = s+ temp;
                m = m/2;
            } else {
                for(int j = 0; j<m-1; j=j+2 ){
                    b[j/2]=a[j]+a[j+1];
                    temp = max(temp, b[j/2]);
                };
                b[m/2] =a[m-1];
                s = s + temp;
                m = m/2 + 1;
            };
        };
        cout << s << endl;
    }; 
}