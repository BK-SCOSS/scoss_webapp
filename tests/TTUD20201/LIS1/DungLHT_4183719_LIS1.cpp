//input
//11
//1 2 3 8 9 10 4 5 6 20 9 10
//output
//8
//1 - 2 - 3 - 4 - 5 - 6 - 9 - 10
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 100005
int n, a[N], F[N];
int m, b[N];
int t;
int main() {
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        // array b, length m, in increasing order
        for (int i = 1; i <= n; i++) {
            F[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
            m = max(m, F[i]);
            b[F[i]] = a[i];
        }

        // m is also max(F)
        printf("%d\n", m);

        int Expected = m;
        vector<int> T;

        // add m elements from a into T
        for (int i = n; i >= 1; i--) {
            if (F[i] == Expected) {
                T.push_back(a[i]);
                Expected--;
            }
        }
        t--;
    }
}
