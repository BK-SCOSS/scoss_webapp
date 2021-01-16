#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n,m;
unsigned long long int a[100000];
unsigned long long int b[100000];


int main() {
    cin >> T;
    while(T--) {
        for (int i=0; i<100 ; i++) {
            a[i] = 0, b[i] = 0;
        }
        cin >> n;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int j=0; j<m; j++) {
            cin >> b[j];
        }

        sort(a, a+n); sort(b, b+m);

        int count=0;

            int i = 0, j = 0;
            int key = a[0];
            while(i<n, j<m) {
                if(a[i]==b[j] && (i==0 || a[i]!=key)) {
                    key = a[i];
                    count++;
                    i++;
                    j++;

                } else if(a[i]>b[j]){
                    j++;

                } else {
                    i++;
                }
            }

        cout << count <<endl;
    }
    return 0;
}
