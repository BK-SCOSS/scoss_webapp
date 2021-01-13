#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
int n,k;
typedef struct thue{
    ll f,s,cost;
    int type;
} thue;

thue a[2000010];
bool compare(const thue &x, const thue &y){
    if(x.f < y.f) return true;
    else if(x.f == y.f) return x.type > y.type;
    else return false;
}
map<ll,ll> dp;
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        v = v + u + k;
        a[2*i].type = 1;
        a[2*i].f = u;
        a[2*i+1].type = 2;
        a[2*i+1].f = v;
        a[2*i+1].s = u;
        a[2*i+1].cost = w;
    }
    sort(a,a+2*n,compare);
    ll res = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if(a[i].type == 1){
            dp[a[i].f] = max(dp[a[i].f],res);
        }
        else{
            res = max(res,dp[a[i].s] + a[i].cost);
        }
    }
    cout << res << endl;
    

    

    return 0;
}