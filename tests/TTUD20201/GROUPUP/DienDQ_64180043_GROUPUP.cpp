#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e5 + 100;
int n;
ll a[N];
ll b[N];

main(){
   // freopen(".inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        ll res = 0;
        while(n > 1){
            ll ma = 0;
            int k = 0;
            for(int i = 1; i < n; i+=2){
                if(ma < a[i] + a[i+1])
                    ma = a[i] + a[i+1];
                b[++k] = a[i] + a[i+1];
            }
            if(n%2 == 1) b[++k] = a[n];
            for(int i = 1; i <= k; ++i) a[i] = b[i];
            n = k;
            res += ma;
        }
        cout << res << "\n";
    }
}
