#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
#define ull unsigned long long

void solve() {
    ll n;
    cin >> n;
    ll t = n * (n + 1) * (n + 2);
    int ans = 0;
    for (int i = 2; i * i <= t * t; i++) {
        if ((t * t) % i == 0 && t % i != 0) {
            ans++;
            ll j = t / i;
            if (j != i && (t * t) % j == 0 && t % j != 0) ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}