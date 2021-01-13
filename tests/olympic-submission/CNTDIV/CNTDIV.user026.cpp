/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn
#define Task "CNTDIV"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int q, n, ans, d[10001];
long long T;

void in()
{
    cin >> q;
}

void fact(long long p, pii (&q)[10001], int &sza)
{
    sza = 0;
    for (int i = 2; i <= 1000; ++i) {
        if (p % i == 0) q[++sza] = mp(i, 0);
        while (p % i == 0) {
            p /= i;
            q[sza].S++;
        }
        q[sza].S *= 2;
        if (p == 1) break;
    }
}

void Backtrack(int id, pii (&q)[10001], int &sza)
{
    if (id > sza) {
        long long cur = 1;
        for (int i = 1; i < id; ++i) {
            int x = d[i];
            while (x) {
                cur *= q[i].F;
                if (cur >= T) return;
                x--;
            }
        }
        if (T % cur == 0) return;
        ans++;
        return;
    }
    for (int i = 0; i <= q[id].S; ++i) {
        d[id] = i;
        Backtrack(id+1, q, sza);
    }
}

long long calc(int n)
{
    if (n <= 1000) {
        ans = 0;
        T = 1ll * n * (n+1) * (n+2);
        pii a[10001];
        int sza;
        fact(T, a, sza);
        Backtrack(1, a, sza);
        return ans;
    }
    return 0;
}

void solve()
{
    while (q--) {
        cin >> n;
        cout << calc(n) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    //freopen(Task".INP", "r", stdin);
    //freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
