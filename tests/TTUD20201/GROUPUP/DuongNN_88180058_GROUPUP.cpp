#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5 + 2;
int n, t;
ll a[N], res;
queue <ll> hd, s;

void inp()
{
    while(!hd.empty()) hd.pop();
    ll x;
    scanf("%d", &n);
    fti(i, 1, n) scanf("%lld", &x), hd.push(x);
}

void proc()
{
    res = 0;
    int cnt;
    ll X1, Max;
    while(true) {
        Max = cnt = 0;
        while(!hd.empty()) {
            X1 = hd.front(); hd.pop();
            if(!hd.empty()) {
                X1 += hd.front(); hd.pop();
                Max = max(Max, X1);
            }
            s.push(X1);
        }
        res += Max;
        while(!s.empty()) hd.push(s.front()), s.pop(), ++ cnt;
        if(cnt == 1) break;
    }
    printf("%lld\n", res);
}

int main()
{
    scanf("%d", &t);
    while(t --) {
        inp();
        proc();
    }
}
