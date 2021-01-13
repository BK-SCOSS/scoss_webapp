#include<bits/stdc++.h>

using namespace std;

#define ff(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;

const int N = 1000000 + 10;

struct re {
    int x;
    int y;
    int c;

    const bool operator < (const re& a) const {
        if (x != a.x) return x < a.x;
        if (y != a.y) return y < a.y;
        return c < a.c;
    }
};

int n, k;
re a[N];
//set<re> b;
vector<re> w;
ll f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ff(i, 1, n) {
        int u, v, c;
        cin >> u >> v >> c;
        v = u + v;
        a[i] = (re){u, v, c};
        w.push_back({u, 0, i});
        w.push_back({v, 1, i});
    }
    sort(w.begin(), w.end());

    ll mx = 0;
    ll res = 0;
    int j = 0;
    ff(i, 0, (int) w.size() - 1) {
        while (j < i && w[j].x + k <= w[i].x) {
            if (w[j].y == 1) {
                mx = max(mx, f[w[j].c]);
            }
            ++j;
        }
        if (w[i].y == 0) {
            f[w[i].c] = max(f[w[i].c], mx + a[w[i].c].c);
            res = max(res, f[w[i].c]);
        }
    }
    cout << res;
}
