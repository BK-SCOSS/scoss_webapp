

#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define fo(i, x, y) for(int i=x; i<=y; i++)
#define rfo(i, x, y) for(int i=x; i>=y; i--)
using namespace std;
const ll oo=1e18;
const int N=1e6+1;
int n, K;
ll dp[N], bit[N];
struct customer
{
    ll s, d, r;
} a[N];
bool cmp(int i, int j)
{
    return a[i].s<a[j].s;
}
/*
ll it[4*N];

void upd(int id, int l, int r, int pos, ll val)
{
    if(pos<l||r<pos) return;
    if(l==r){
        it[id]=max(it[id], val);
        return;
    }
    int mid=(l+r)/2;
    upd(2*id, l, mid, pos, val);
    upd(2*id+1, mid+1, r, pos, val);
    it[id]=max(it[2*id], it[2*id+1]);
}
ll get(int id, int l, int r, int l1, int r1)
{
    if(r1<l||r<l1) return 0;
    if(l1<=l&&r<=r1) return it[id];
    int mid=(l+r)/2;
    ll t1=get(2*id, l, mid, l1, r1);
    ll t2=get(2*id+1, mid+1, r, l1, r1);
    return max(t1, t2);
}*/
ll get(int x)
{
    ll res=0;
    while(x){
        res=max(bit[x], res);
        x-=x&(-x);
    }
    return res;
}
void upd(int x, ll val)
{
    while(x<=n){
        bit[x]=max(bit[x], val);
        x+=x&(-x);
    }
}
main()
{
	ios_base::sync_with_stdio(false); cin.tie();
    //freopen("read.inp", "r", stdin);
	//freopen("read.out", "w", stdout);
	int test=1;
	//cin>>test;
	while(test--){
        cin>>n>>K;
        vector<int> v;
        vector<ll> v1;
        for(int i=1; i<=n; ++i){
            cin>>a[i].s>>a[i].d>>a[i].r;
            a[i].d+=a[i].s+K-1;
            v1.pb(a[i].d);
            v.pb(i);
        }
        sort(v.begin(), v.end(), cmp);
        sort(v1.begin(), v1.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        n=v1.size();
        ll ans=0, res;
        int id, r;
        for(int i=0; i<v.size(); ++i){
            id=v[i];
            r=lower_bound(v1.begin(), v1.end(), a[id].s)-v1.begin();
            dp[i+1]=get(r)+a[id].r;
            r=lower_bound(v1.begin(), v1.end(), a[id].d)-v1.begin()+1;
            upd(r, dp[i+1]);
            ans=max(ans, dp[i+1]);
        }
        cout<<ans<<endl;
	}
}
