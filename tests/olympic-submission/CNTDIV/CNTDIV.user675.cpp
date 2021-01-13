#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 2;
int cnt[N+1],dvs[N+1];

int solve(int n) {
    int n0 = n;
    int n1 = n+1;
    int n2 = n+2;
    LL t1 = 1, t2 = 1;
    while (n0 > 1) {
        int div;
        int c = 0;
        div = dvs[n0];
        while (n0 % div == 0) {
            ++c;
            n0 /= div;
        }
        while (n1 % div == 0) {
            ++c;
            n1 /= div;
        }
        while (n2 % div == 0) {
            ++c;
            n2 /= div;
        }

        t1 *= (c+1);
        t2 *= (2*c+1);

    }

    while (n1 > 1) {
        int div;
        int c = 0;
        div = dvs[n1];
        while (n0 % div == 0) {
            ++c;
            n0 /= div;
        }
        while (n1 % div == 0) {
            ++c;
            n1 /= div;
        }
        while (n2 % div == 0) {
            ++c;
            n2 /= div;
        }

        t1 *= (c+1);
        t2 *= (2*c+1);
    }

    while (n2 > 1) {
        int div;
        int c = 0;
        div = dvs[n2];
        while (n0 % div == 0) {
            ++c;
            n0 /= div;
        }
        while (n1 % div == 0) {
            ++c;
            n1 /= div;
        }
        while (n2 % div == 0) {
            ++c;
            n2 /= div;
        }

        t1 *= (c+1);
        t2 *= (2*c + 1);
    }

    return t2/2 - t1 + 1;

}


int main() {


    dvs[1] = 1e9;
    for (int i = 2 ; i <= N ; ++ i)
        if (!dvs[i]) {
            dvs[i] = i;
            for (int j = i ; j <= N/i ; ++ j)
                dvs[j*i] = i;
        }

    int tc;
    scanf("%d",&tc);
    while (tc--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",solve(n));
    }
    return 0;
}
