#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

map <int, int> b;
const int N = 1e5 + 2;
int n, a[N], res, t;

void inp()
{
    scanf("%d", &n);
    fti(i, 1, n) scanf("%d", &a[i]);
}

void proc()
{
    res = 0;
    b.clear();
    fti(i, 1, n) {
        b[a[i]] = max(b[a[i]], b[a[i] - 1] + 1);
        res = max(res, b[a[i]]);
    }
    printf("%d\n", res);
}

int main()
{
    scanf("%d", &t);
    while(t --) {
        inp();
        proc();
    }
}
