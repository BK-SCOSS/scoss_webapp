#include <bits/stdc++.h>
using namespace std;

struct data{
    long long s, f, r;
};

long long n, m, k, res;
long long t[1000100];
map <long long, long long> mapp;
data a[1000100];
vector<long long> v;


bool cmp(data a, data b) {
    return a.s < b.s;
}

void update(long long k, long long x) {
    for (long long i = k; i <= m; i += i&-i)
        t[i] = max(t[i], x);
}
long long query(long long k) {
    long long res = 0;
    for (long long i = k; i > 0; i &= i-1)
        res = max(res, t[i]);
    return res;
}

int main() {
    //freopen("facility.inp","r",stdin);
    //freopen("facility.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].s >> a[i].f >> a[i].r;
        a[i].f += a[i].s + k;

        v.push_back(a[i].s);
        v.push_back(a[i].f);
    }

    sort(a + 1, a + 1 + n, cmp);
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    m = v.size();
    for (int i = 0; i < v.size(); ++i)
        mapp[v[i]] = i+1;

    res = 0;

    for (int i = 1; i <= n; ++i) {
         long long s = mapp[a[i].s];
         long long f = mapp[a[i].f];
         long long r = a[i].r;

         //cout << s << " " << f << " " << r << endl;

         long long x = query(s) + r;
         update(f, x);

         res = max(res, x);
    }
    cout << res;
}
