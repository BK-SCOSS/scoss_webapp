#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  unsigned int
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "cogang"
using namespace std;
const int maxn = 1e6 + 5;
struct data{
    LL s,d,r;
    data(){
        s = d = r = 0;
    }
    data(LL A,LL B,LL C){
        A = s; B = d; C = r;
    }
    bool operator < (const data &A)const{
        return s < A.s;
    }
} a[maxn];
int n,k;
long long BIT[maxn * 2 + 5];
vector <LL> V;
///--------------------------
void    readf(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].s >> a[i].d >> a[i].r;
        a[i].d += a[i].s + k;
        V.eb(a[i].s);
        V.eb(a[i].d);
    }
    sort(a + 1, a + n + 1);
    sort(V.begin(),V.end());
    __unique(V);
}
///--------------------------
inline int id(int x){
    return upper_bound(V.begin(),V.end(),x) - V.begin();
}
///--------------------------
void    update(int x, long long val){
    for( ; x < 2 * maxn; x += -x & x) BIT[x] = max(BIT[x],val);
}
///--------------------------
long long  get(int x){
    long long tmp = 0;
    for( ; x > 0; x -= -x & x) tmp = max(tmp,BIT[x]);
    return tmp;
}
///--------------------------
void    solve(){
    for(int i = 1; i <= n; ++i){
        a[i].s = id(a[i].s);
        a[i].d = id(a[i].d);
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        long long tmp = get(a[i].s) + a[i].r;
        update(a[i].d,tmp);
        ans = max(ans,tmp);
    }
    cout << ans << '\n';
}
///--------------------------
int     main(){
	srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    readf();
    solve();
}




