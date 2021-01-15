#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<pl, ll> pll;

int n, k;
ll res[maxn], ans;
pll a[maxn];
pl b[maxn];
map<ll, ll> mp, mp2;
bool comp(const pll &x,const pll &y){
    return x.F<y.F;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("20BKOIC.inp", "r", stdin);
    //freopen("20BKOIC.out", "w", stdout);
    cin>>n>>k;
    for (int i=1; i<=n; ++i){
        cin>>a[i].F.F>>a[i].F.S>>a[i].S;
        a[i].F.S+=a[i].F.F+k-1;
        b[i]=pl(a[i].F.F, 1);
        b[i+n]=pl(a[i].F.S, 2);
    }
    sort(a+1, a+n+1, comp);
    for (int i=1; i<=n; ++i){
        for (int j=0; j<i; ++j)
        if (a[j].F.S<a[i].F.F){
            res[i] = max(res[i], res[j]+a[i].S);
        }
        ans = max(ans, res[i]);
    }
    /*sort(b+1, b+2*n+1);
    int hold = 0;
    for (int i=1; i<=2*n; ++i){
        if (b[i].F != hold) mp[b[i].F] = hold;
        else mp[b[i].F] = mp[hold];
        if (b[i].S==2) hold = b[i].F;
    }
    long long ans = 0;
    for (int i=1; i<=n; ++i){
        hold = a[i].F.F;
        //cout<<a[i].F.F<<" "<<a[i].F.S<<" "<<a[i].S<<endl;
        mp2[a[i].F.S]=max(mp2[a[i].F.S], mp2[mp[hold]]+a[i].S);
        ans=max(ans, mp2[a[i].F.S]);
    }*/
    cout<<ans<<endl;
    return 0;

}
