
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
const int N=1e5;
const int M=1e5+1;
const ll mod=(1e9)+7;
ll gt[M], inv[M], ans=0;
int L, S, T, n;
ll C(int x, int y)
{
    if(x>y) return 0;
    return gt[y]*inv[x]%mod*inv[y-x]%mod;
}
ll PW(ll x, int y)
{
    if(y==0) return 1;
    ll res=PW(x, y/2);
    res=res*res%mod;
    if(y%2) res=res*x%mod;
    return res;
}
void solve(int x)
{
    if(L<0||((L%2)!=(x%2))||L<x) return;
    int cnt=(S%3==1)?(x/2+1):((x+1)/2);
    int tmp=(L-x)/2;
    for(int i=0; i<=tmp; i++){
        ll t=C(i, 2*i+x);
        ll t1=C(cnt-1, tmp-i+cnt-1);
        ans=(ans+t*t1%mod)%mod;
        cnt++;
    }
}
int dist(int x, int y)
{
    if(x>y) swap(x, y);
    int res=0;
    while(x+3<=y){
        x+=3;
        res+=2;
    }
    if(x<y) res++;
    return res;
}
main()
{
	ios_base::sync_with_stdio(false); cin.tie();
    //freopen("read.inp", "r", stdin);
	//freopen("read.out", "w", stdout);
	int test=1;
	//cin>>test;
	gt[0]=1;
	inv[0]=PW(1, mod-2);
	for(int i=1; i<=N; i++){
        gt[i]=gt[i-1]*(ll)i%mod;
        inv[i]=PW(gt[i], mod-2);
	}
	while(test--){
        cin>>n>>L>>S>>T;
        if(L<=N){
            if(L==0){
                if(S!=T) cout<<0<<endl;
                else cout<<1<<endl;
            }
            else{
                if(S%3==2){
                    S--;
                    L--;
                }
                if(T%3==2){
                    T--;
                    L--;
                }
                int t1=dist(S, T);
                solve(t1);
                t1=2*n-t1;
                solve(t1);
                cout<<ans<<endl;
            }
        }
	}
}
