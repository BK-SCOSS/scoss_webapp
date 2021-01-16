#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e5 + 100;
int n,t;
int a[N];
map<ll,ll> m;

main(){
  //  freopen(".inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        m.clear();
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        ll res = 0;
        for(int i = 1; i <= n; ++i){
            int x = a[i];
            ll c = m[x-1] + 1;
            if(m[x] < c) m[x] = c;
            res = max(res,c);
        }
        cout << res << "\n";
    }
}
