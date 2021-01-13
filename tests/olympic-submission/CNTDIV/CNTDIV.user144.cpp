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
const ll  N=1e6;
int p[N+1], n;
main()
{
	ios_base::sync_with_stdio(false); cin.tie();
    //freopen("read.inp", "r", stdin);
	//freopen("read.out", "w", stdout);
	p[1]=1;
	for(int i=1; i<=N; i++){
        if(!p[i]){
            for(int j=i; j<=N; j+=i){
                if(!p[j]) p[j]=i;
            }
        }
	}
	int test=1;
	cin>>test;
	while(test--){
        cin>>n;
        vector<int> v, v1;
        for(int i=n; i<=n+2; i++){
            int t=i;
            while(t>1){
                v.pb(p[t]);
                t/=p[t];
            }
        }
        sort(v.begin(), v.end());
        v1.pb(1);
        for(int i=1; i<v.size(); i++){
            if(v[i]!=v[i-1]) v1.pb(0);
            v1.back()++;
        }
        ll t1=1, t2=1;
        for(int i=0; i<v1.size(); i++){
            t1*=(ll)(v1[i]+1);
            t2*=(ll)(2*v1[i]+1);
        }
        ll ans=(t2-2LL*t1+1LL)/2LL;
        cout<<ans<<endl;
	}
}

