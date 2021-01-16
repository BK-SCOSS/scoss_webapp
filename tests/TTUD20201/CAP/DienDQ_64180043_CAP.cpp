#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

ll a[500],b[500];

main(){
   // freopen(".inp","r",stdin);
  //  freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,m;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a+1,a+n+1);
        cin >> m;
        for(int i = 1; i <= m; ++i)
            cin >> b[i];
        sort(b+1,b+m+1);
        ll res = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] == a[i+1]) continue;
            int y = 0;
            for(int j = 1; j <= m; ++j)
                if(b[j] == a[i]) ++y;
            if(y > 0) ++res;
        }
        cout << res << "\n";
    }
}
