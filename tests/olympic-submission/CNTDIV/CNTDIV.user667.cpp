#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

const int N = 2*1e5 + 2, M = 1e6 + 4;
int n, t, cnt, snt[N], dem[N], pos[M];
ll res, res1;
bool ok[M];
vector <int> a;

void inp()
{
    scanf("%d", &n);
}

void proc()
{
    int j;
    for(int i = 2; i * i <= M - 2; ++ i) {
        if(!ok[i]) {
            j = 2;
            while(i * j <= M - 2) ok[i * j] = true, ++ j;
        }
    }
    fti(i, 2, M - 2) if(!ok[i]) snt[++ cnt] = i, pos[i] = cnt;
}

void pttsnt(int x)
{
    int cnt0 = 1;
    while(x > 1) {
        if(!ok[x]) {
            a.pb(pos[x]);
            ++ dem[pos[x]];
            break;
        }
        if(x % snt[cnt0] == 0) {
            a.pb(cnt0);
            while(x % snt[cnt0] == 0) x /= snt[cnt0], ++ dem[cnt0];
        }
        ++ cnt0;
    }
}

void solve()
{
    res = res1 = 1;
    //while(!a.empty()) dem[a.back()] = 0, a.pop_back();
    pttsnt(n);
    pttsnt(n + 1);
    pttsnt(n + 2);
    fti(i, 0, int(a.size() - 1)) {
        res *= (2 * dem[a[i]] + 1);
        res1 *= dem[a[i]] + 1;
        //cout << dem[a[i]] << " " << snt[a[i]] << "\n";
        dem[a[i]] = 0;
    }
    a.clear();
    //cout << res << " " << res1 << "\n";
    res -= 2 * res1;
    ++ res; res /= 2;
    printf("%lld\n", res);
}

int main()
{
    proc();
    scanf("%d", &t);
    fti(i, 1, t) {
        inp();
        solve();
    }
}
