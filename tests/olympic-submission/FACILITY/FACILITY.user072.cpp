#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll pow(ll n, ll p) {
    ll s = 1;
    while (p > 0) {
        s *= n;
        --p;
    }
    return s;
}

void fact(ll n, vector<ll> &base, vector<ll> &p) {
    if (n == 0) {
        base = {0};
        p = {1};
        return;
    } else if (n == 1) {
        base = {1};
        p = {1};
        return;
    }
    base = {};
    p = {};
    for (ll i = 2; n != 1; ++i) {
        ll j = 0;
        while (n % i == 0) {
            ++j;
            n /= i;
        }
        if (j > 0) {
            base.push_back(i);
            p.push_back(j);
        }
    }
}

ll eval(vector<ll> &base, vector<ll> &x) {
    ll s = 1;
    for (size_t i = 0; i < base.size(); ++i) {
        int t = pow(base[i], x[i]);
        s *= t;
    }
    return s;
}

void tryi(vector<ll> &base, vector<ll> &p, vector<ll> &x, ll t, size_t i, ll &c) {
    if (i == base.size()) {
        ll s = eval(base, x);
        if (s < t && t % s != 0) {
            ++c;
        }
    } else {
        for (ll j = 0; j <= 2 * p[i]; ++j) {
            x[i] = j;
            tryi(base, p, x, t, i + 1, c);
        }
    }
}

ll solution(ll n) {
    ll t = n * (n + 1) * (n + 2);

    vector<ll> base, p;
    fact(t, base, p);

    ll c = 0;
    vector<ll> x(base.size());
    tryi(base, p, x, t, 0, c);
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;
    ll a;
    for (int i = 0; i < t; ++i) {
        cin >> a;
        cout << solution(a) << '\n';
    }
    return 0;
}
