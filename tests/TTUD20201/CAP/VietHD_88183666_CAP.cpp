#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1007], b[107], res=0;
short bmark[107];
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    long long t; cin >> t;
    while (t--){
        res=0;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(bmark, 0, sizeof bmark);

        cin >> n;
        for (long long i=0; i<n; ++i) cin >> a[i];
        cin >> m;
        for (long long j=0; j<m; ++j) cin >> b[j];

        for (long long i=0; i<n; ++i)
            for (long long j=0; j<m; ++j){
                if (a[i] == b[j] && !bmark[j]){
                    res++;
                    bmark[j] = 1;
                } 
            }
        cout << res;
    }
    return 0;
}