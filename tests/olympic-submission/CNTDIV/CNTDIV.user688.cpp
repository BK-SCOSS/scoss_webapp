#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

int main()
{
    ll n,k;
    cin >> n >>k;
    vector<pair<ll, pair<ll,ll>>> d;
    vector<ll> s(n);
    vector<ll> e(n);
    vector<ll> r(n);
    for(int i=0;i<n;i++){
        ll x,y,z;
        cin >> x >> y >> z;
        d.push_back({x+y,{x,z}});
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    ll cur_time = 0;
    for(auto x : d){
        if(x.S.F >= cur_time){
            ans += x.S.S;
            cur_time = x.S.F + k;
        }
    }
    cout << ans << endl;
    return 0;
}
