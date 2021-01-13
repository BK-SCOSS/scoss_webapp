#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)

using namespace std;

const int N = 1e5 + 1e4;
int n, res[N], d[8], T;
bool ok[10];

void inp()
{
    scanf("%d", &n);
}

void update()
{
    int S = d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[4] + d[3] * 10000 + d[5] * 1000 + d[6] * 100 + d[7] * 10 + d[4];
    ++ res[S];
}

void btr(int u)
{
    if(u > 7) {
        update();
        return;
    }
    fti(i, 0, 9) {
        if((u == 3 || u == 1) && i == 0) continue;
        if(!ok[i]) {
            ok[i] = true;
            d[u] = i;
            btr(u + 1);
            ok[i] = false;
        }
    }
}

void proc()
{
    btr(1);
}

void solve()
{
    proc();
    scanf("%d", &T);
    while(T --) {
        inp();
        if(n >= N) printf("0\n");
        else printf("%d\n", res[n]);
    }
}

int main()
{
    solve();
    return 0;
}
