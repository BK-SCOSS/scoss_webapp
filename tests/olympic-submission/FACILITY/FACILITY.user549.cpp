#include <stdio.h>
#include <iostream>
using namespace std;
int compare(const void *a, const void *b) {
    const long long int *x =   (long long int*) a;
    const long long int *y =   (long long int*) b;

    if (x[1] > y[1]) return 1;
    if (x[1] < y[1]) return -1;

    if (x[0] > y[0]) return 1;
    if (x[0] < y[0]) return -1;

    if (x[2] > y[2]) return 1;
    if (x[2] < y[2]) return -1;
    return 0;
}

int main() {
    long long int n, K, i, j;
    long long int maximum = - __LONG_LONG_MAX__;
    cin >> n >> K;

    long long int a[n][3], max[n];
    
    for (i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1] += a[i][0] + K;
    }

    qsort(a, n, sizeof(long long int) * 3, compare);


    for (i = 0; i < n; i++) {
        max[i] = a[i][2];
        if (i >= 1) {
            for (j = 0; j <= i - 1; j++) {
                if (a[j][1] <= a[i][0] && max[i] < max[j] + a[i][2]) {
                    max[i] = max[j] + a[i][2];
                }
            }
            if (maximum < max[i]) {
                maximum = max[i];
            }
        }
    }
    cout << maximum;
}