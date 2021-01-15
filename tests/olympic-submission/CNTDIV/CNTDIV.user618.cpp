#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; i++)
#define maxn 1000006
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int q, n;

void input()
{
    //freopen("cntdiv.inp", "r", stdin);
    //freopen("cntdiv.out", "w", stdout);
    cin >> q;
}

int d[maxn];
const int N=1e6+2;
void snt ()
{
    fto (i, 1, N) d[i]=i;
    fto (i, 2, sqrt(N)) if (d[i]==i) {
        int j=i*i;
        while (j<=N){
            d[j]=i;
            j+=i;
        }
    }
}

pii sl[maxn][20];
int cnt[maxn];

void pre()
{
    fto (i, 2, N) {
        int x=i;
        while (x!=1) {
            int y=d[x], dem=0;
            while (x%y==0) {
                ++dem;
                x/=y;
            }
            sl[i][++cnt[i]]={y, dem};
        }
    }
}

priority_queue <pii> tg;
void solve()
{
    fto (i, 1, q) {
        cin >> n;
        fto (j, 1, cnt[n]) tg.push(sl[n][j]);
        fto (j, 1, cnt[n+1]) tg.push(sl[n+1][j]);
        fto (j, 1, cnt[n+2]) tg.push(sl[n+2][j]);
        long long res=1, res2=1;
        int sl=0, last=0;
        int Liinhh = tg.size();
        while (!tg.empty()) {
            int x=tg.top().fi;
            int y=tg.top().se;
            tg.pop();
            if (x==last) sl+=y;
            else {
                res2*=(sl+1);
                sl=sl*2+1;
                res*=sl;
                last=x;
                sl=y;
            }
        }
        if (Liinhh >1) {res2*=(sl+1); sl=sl*2+1; res*=sl;}
        res=(res+1)/2-res2;
        cout << res << '\n';
    }
}

int main()
{
    input();
    snt();
    pre();
    solve();
    return 0;
}
