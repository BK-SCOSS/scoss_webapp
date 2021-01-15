#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
tuple<long long, long long, long long> a[N]; 
int n, k;
long long f[N];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        long long s, d, r;
        scanf("%lld%lld%lld", &s, &d, &r);
        a[i] = make_tuple(s + d + k, s, r);
    }
    sort(a + 1, a + n + 1);
    a[0] = make_tuple(-1e9, 0, 0);
    for(int i = 1; i <= n; i ++) {
        int l = 0, r = i - 1;
        while(l < r) {
            int m = (l + r + 1) / 2;
            if(get<0>(a[m]) <= get<1>(a[i])) {
                l = m;
            }
            else r = m - 1;
        }
        f[i] = max(f[i - 1], f[l] + get<2>(a[i]));
    }
    printf("%lld", f[n]);
}