#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

const int N = 102;
int n, t, a[N], b[N], m, res, c[N], d[N], cnt1, cnt2;

void inp()
{
    scanf("%d", &n);
    fti(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    fti(i, 1, m) scanf("%d", &b[i]);
}

void proc()
{
    cnt1 = cnt2 = 0;
    sort(a + 1, a + n + 1);
    fti(i, 1, n) if(a[i] != a[i - 1]) c[++ cnt1] = a[i];
    sort(b + 1, b + m + 1);
    fti(i, 1, m) if(b[i] != b[i - 1]) d[++ cnt2] = b[i];
    res = 0;
    fti(i, 1, cnt1)
        fti(j, 1, cnt2) if(c[i] == d[j]) ++ res;
    printf("%d\n", res);
}

int main()
{
    //freopen("CAP.inp", "r", stdin);
    scanf("%d", &t);
    while(t --) {
        inp();
        proc();
    }
}
