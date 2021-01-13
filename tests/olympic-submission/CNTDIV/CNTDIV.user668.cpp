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
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "cogang"
using namespace std;
const int maxn = 1e6 + 5;
int pr[maxn],pw[maxn];
///--------------------------
void    readf(){

}
///--------------------------
void    sieve(){
    for(int i = 2; i * i < maxn; ++i)
        if (pr[i] == 0)
            for(int j = i * i; j < maxn; j += i)
                pr[j] = (pr[j] == 0 ? i : pr[j]);
    for(int i = 2; i < maxn; ++i) if (pr[i] == 0) pr[i] = i;
}
///--------------------------
void    split(vector <ii> &A,int k){
    while (k > 1){
        int prime = pr[k];
        int cnt = 0;
        while (k % prime == 0){
            k /= prime;
            cnt++;
        }
        A.eb(prime,cnt);
    }
}
///--------------------------
void    solve(){
    sieve();
    int Q;
    cin >> Q;
    while (Q--){
        int n;
        cin >> n;
        LL ansT2 = 1, ansT = 1;
        vector <ii> tsnt;
        vector <int> prime;
        split(tsnt, n);
        split(tsnt, n + 1);
        split(tsnt, n + 2);
        for(auto i : tsnt){
            prime.eb(i.fi);
            pw[i.fi] = 0;
            //cerr << i.fi <<' ' << i.se << '\n';
        }
        sort(prime.begin(),prime.end());
        __unique(prime);
        for(auto i : tsnt) pw[i.fi] += i.se;
        for(auto i : prime) ansT2 *= (2 * pw[i] + 1);
        for(auto i : prime) ansT *= (pw[i] + 1);
        cout << (ansT2 - (ansT2 - 1 >> 1) - ansT) << '\n';
    }
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




