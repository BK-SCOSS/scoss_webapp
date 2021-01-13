#include <bits/stdc++.h>
using namespace std;

long long n, res1, res2;
vector<long long> a;
long long c[1000100];

void eratos() {
    memset(c, -1, sizeof(c));
    c[1] = 1;
    for (long long i = 2; i <= 1000002; ++i)
        if (c[i] == -1) {
            c[i] = i;
            for (long long j = i * i; j <= 1000002; j += i)
                c[j] = i;
        }
}

void solve(long long x) {
    while (x != 1) {
        long long z = c[x];
        a.push_back(z);
        while (x % z == 0) x /= z;
    }
}

void cal(long long x) {
    for (long long i = 0; i < a.size(); ++i) {
        long long y = a[i];

        if (x % y != 0) continue;

        long long cnt = 0;
        while (x % y == 0) {
            cnt++;
            x /= y;
        }
        //cout << y << " " << cnt << endl;
        res1 = res1 * (cnt + 1);
        res2 = res2 * (cnt + cnt + 1);
    }
}

int main() {
    int test;
    cin >> test;

    eratos();

    while (test--) {
        cin >> n;
        a.clear();
        for (long long i = n; i <= n+2; ++i)
            solve(i);

        //for (int i = 0 ; i < a.size(); ++i) cout << a[i] << " "; cout << endl;

        res1 = res2 = 1;
        cal(n * (n+1) * (n+2));

        cout << (res2 + 1) / 2 - res1 << endl;
    }
}
