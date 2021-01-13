#include <bits/stdc++.h>

#define MAX_INT 2e9
#define maxl 1000000
#define ln length()
#define ff(i,a,b) for(int i = a; i <= b; i++)
#define fb(i,a,b) for(int i = a; i >= b; i--)
typedef long long ll;
using namespace std;

ll q, n, t, tt, cnt;

ll countfactor(ll t) {
    // cout << t << endl;
    unordered_map< ll, ll > prfac;
    for (ll i = 2; i <= sqrt(t); i++) {
        while (t % i == 0) {
            prfac[i]++;
            t /= i;
        }
    }
    if (t > 2) prfac[t]++;
    
    // for (auto it: prfac) {
    //     cout << '(' << it.first << ", " << it.second << ')' << endl;
    // }

    int res1 = 1, res2 = 1;
    for (auto it: prfac) {
        res1 *= (it.second * 2 + 1);
        res2 *= (it.second + 1);
    }
    // cout << res1 << " " << res2 << endl;
    return res1/2 - res2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cnt = 0;
        cin >> n;
        t = n * (n + 1) * (n + 2);
        cout << countfactor(t) << endl;
    }
}
