#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e6;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,long long> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,k;
long long res,Max,dp[N+5];
struct Clara
{
    int l,r;
    long long v;
    Clara(int L=0, int R=0, long long V=0) {l=L; r=R; v=V;}
} a[N+5];
bool cmp(Clara X, Clara Y) {return X.l<Y.l;}
set<ii> s;
int main()
{
	//freopen("FACILITY.inp","r",stdin);
	//freopen("FACILITY.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int l,r;
        long long v;
        cin>>l>>r>>v;
        a[i]=Clara(l,l+r-1,v);
    }
    sort(a+1,a+1+n,cmp);
    //for (int i=1;i<=n;i++) cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<endl;
    for (int i=1;i<=n;i++)
    {
        while (!s.empty() && (*s.begin()).fs<a[i].l)
        {
            Max=max(Max,(*s.begin()).sd);
            s.erase(s.begin());
        }
        dp[i]=Max+a[i].v;
        res=max(res,dp[i]);
        s.insert(ii(a[i].r+k,dp[i]));
    }
    cout<<res;
	return 0;
}
