#include <bits/stdc++.h>
#define ii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

struct data{
    int s,d,r;
};

const int N = 1e6 + 100;
data a[N];
ll f[N];
int n,k;

bool cmp(data x,data y){
    return x.s + x.d < y.s + y.d;
}

main(){
  //  freopen(".inp","r",stdin);
 //   freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].s >> a[i].d >> a[i].r;
    }
    a[0] = {int(-1e9),0,0};
    sort(a+1,a+n+1,cmp);
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        int l = 1,r=i-1;
        int d = 0;
        while(l <= r){
            int g = (l+r)/2;
            if(a[g].s + a[g].d + k <= a[i].s)
                d = g,l = g+1;
            else
                r = g-1;
        }
        f[i] = max(f[i-1],f[d] + a[i].r);
    }
    cout << f[n];
}
