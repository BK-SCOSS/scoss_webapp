#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000004;

int f[nmax], p[nmax/4], np, cnt[nmax];

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    for (int i = 2; i < nmax; ++i){
        if (f[i] == 0) f[i] = p[np++] = i;
        for (int j = 0; j < np && p[j] <= f[i] && p[j]*i < nmax; ++j) f[p[j]*i] = p[j];
    }
    int t;
    scanf("%d", &t);
    assert(t <= 100000);
    while(t--){
        int n;
        scanf("%d", &n);
        assert(n <= 1000000);
        vector<int> lst;
        for (int x : {n, n+1, n+2}){
            while(x != 1){
                int u = f[x];
                lst.push_back(u);
                while(x % u == 0){
                    ++cnt[u];
                    x /= u;
                }
            }
        }
        sort(lst.begin(), lst.end());
        lst.resize(unique(lst.begin(), lst.end()) - lst.begin());
        long long TT = 1, T = 1;
        for (int p : lst){
            T *= cnt[p] + 1;
            TT *= cnt[p]*2 + 1;
            cnt[p] = 0;
        }
        TT /= 2;
        printf("%lld\n", TT-T+1);
    }
}
