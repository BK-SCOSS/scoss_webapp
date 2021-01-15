#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e4 + 2, MOD = 1e9 + 7;
int n, L, s, t, f[3 * N];
bool ok[3 * N];

void inp()
{
    scanf("%d %d %d %d", &n, &L, &s, &t);
}

queue <int> hd;

ll BFS()
{
    int l = 1, X, l0, u = 0;
    hd.push(s); f[s] = 1;
    while(!hd.empty()) {
        l0 = 0;
        fti(i, 1, l) {
            X = hd.front();
            ok[X] = false;
            hd.pop();
            if(X % 3 == 0) {
                f[X - 2] += f[X]; f[(X + 1) % (3 * n)] += f[X];
                f[X - 2] %= MOD; f[(X + 1) % (3 * n)] %= MOD;
                if(!ok[X - 2]) ok[X - 2] = true, hd.push(X - 2), ++ l0;
                if(!ok[(X + 1) % (3 * n)]) ok[(X + 1) % (3 * n)] = true, hd.push((X + 1) % (3 * n)), ++ l0;
            }
            if(X % 3 == 1) {
                f[X + 2] += f[X]; f[X + 1] += f[X];
                f[X + 2] %= MOD; f[X + 1] %= MOD;
                if(X == 1) {
                    f[3 * n] += f[X], f[3 * n] %= MOD;
                    if(!ok[3 * n]) ok[3 * n] = true, hd.push(3 * n), ++ l0;
                }
                else {
                    f[X - 1] += f[X]; f[X - 1] %= MOD;
                    if(!ok[X - 1]) ok[X - 1] = true, hd.push(X - 1), ++ l0;
                }
                if(!ok[X + 1]) ok[X + 1] = true, hd.push(X + 1), ++ l0;
                if(!ok[X + 2]) ok[X + 2] = true, hd.push(X + 2), ++ l0;
            }
            if(X % 3 == 2) {
                f[X - 1] += f[X]; f[X - 1] %= MOD;
                if(!ok[X - 1]) ok[X - 1] = true, hd.push(X - 1), ++ l0;
            }
            f[X] = 0;
        }
        //fti(i, 1, 3 * n) cout << f[i] << " ";
        //cout << "\n";
        ++ u;
        if(u == L) break;
        l = l0;
    }
    return f[t];
}

void proc()
{
    printf("%lld\n", BFS());
}

int main()
{
    inp();
    proc();
}
