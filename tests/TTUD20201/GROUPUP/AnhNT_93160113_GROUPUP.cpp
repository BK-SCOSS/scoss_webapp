#include <bits/stdc++.h>
using namespace std;
int T,n,u;
int a[100000];

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 1; i<=n; i++) {
            cin >> a[i];
        }

        int count=0;

        while (n>1) {
            int sum = 0;
            for (int i=1; i<=n; i = i + 2) {
                a[i] += a[i+1];

                if (a[i] > sum) sum=a[i];
                a[i+1] = 0;
            }


            for (int i=1; i<=n/2; i++){
                a[i]=a[2*i-1];
            }

            if (n%2==0) n=n/2;
            else{
                a[n/2+1] = a[n];
                n=n/2+1;
            }
            count += sum;
        }
        cout << count;
    }
    return 0;
}
