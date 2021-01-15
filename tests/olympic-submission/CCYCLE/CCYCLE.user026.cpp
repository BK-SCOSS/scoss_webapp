/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 30007
#define Task "CCYCLE"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, l, s, t, lab[maxn];
long long ans = 0;
vector <int> a[maxn];

void in()
{
    cin >> n >> l >> s >> t;
}

void DFS(int u)
{
    int x = lab[u];
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        lab[v] = lab[u] + 1;
        if (lab[v] == l && v == t) {
            ans = (ans + 1) % maxC;
            continue;
        }
        if (lab[v] >= l && v != t) {
            continue;
        }
        DFS(v);
        lab[u] = x;
    }
}

void solve()
{
    for (int i = 0; i <= 3*n-2; ++i) {
        a[3*i+1].pb(3*i+2);
        a[3*i+2].pb(3*i+1);
        a[3*i+1].pb(3*i+3);
        a[3*i+3].pb(3*i+1);
        if (!i) {
            a[3*i+1].pb(3*n);
            a[3*n].pb(3*i+1);

        } else {
            a[3*i+1].pb(3*i);
            a[3*i].pb(3*i+1);
        }
    }
    lab[s] = 0;
    DFS(s);
    cout << ans;
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
