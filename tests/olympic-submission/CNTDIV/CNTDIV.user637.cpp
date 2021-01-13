#include<bits/stdc++.h>
#define int unsigned long long
#define fi first
#define se second
#define bit(i,j) ((i>>j)&1)
using namespace std;
//---------------------------------------
void read(){}
template<class T, class ...V> void read(T &x,V& ...y)
{
    x=0;
    char c=getchar();
    int ok=(c=='-');
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48, c=getchar();
    if(ok) x=-x;
    read(y...);
}
template<class T>void write(T x)
{
    if(x<0) putchar('-'), x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T,typename V> T max(T& a,V& b){return (a>b)?a:b;}
template<typename T,typename ...V> T max(T& a, V&... b){return max(a,max(b...));}

template<typename T,typename V> T min(T& a,V& b){return (a>b)?b:a;}
template<typename T,typename ...V> T min(T& a, V&... b){return min(a,min(b...));}
//-----------------------------------------------
typedef pair<int,int> pi;
const int mn=1e5+9;
const int mn2=2e6+9;
int p[mn2],q,n,t;
int b[mn];
map<int,int> mp;
vector<pi> a;
void nt(int mn)
{
    for(int i=2;i<=mn;i++)
        p[i]=i;
    for(int i=2;i<=sqrt(mn);i++)
        if(p[i]==i)
        for(int j=i*i;j<=mn;j+=i)
        p[j]=i;
}
void xuli(int a)
{
    //cout<<a<<" "<<p[a]<<'\n';
    while(p[a]!=0)
    {
        mp[p[a]]++;
        a/=p[a];
    }
}
int calc(int i,int ok,int x)
{
    if(i==a.size())
    {
        //if(ok==1)
       // cout<<t%x<<" "<<x<<'\n';
        return ok==1;
    }
    pi m=a[i];
    int tmp=1;
    int res=0;
    for(int j=0;j<=2*m.se;j++)
    {
        if(j>0)
            tmp=tmp*m.fi;
        if(x*tmp>t)break;
            res+=calc(i+1,ok|j>m.se,x*tmp);
    }
   // cout<<i<<" "<<ok<<" "<<x<<" "<<x*tmp<<'\n';
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>q;
    int bx=0;
    for(int i=1;i<=q;i++)
        cin>>b[i],bx=max(b[i]+2,bx);
    nt(bx);
    for(int i=1;i<=q;i++)
    {
        mp.clear();
        a.clear();
        n=b[i];
        t=n*(n+1)*(n+2);
        //cout<<t<<'\n';
        xuli(n);
        xuli(n+1);
        xuli(n+2);
        //cerr<<1<<'\n';
        for(auto it:mp)
        {
            pi x=it;
            a.push_back(x);
            //cout<<x.fi<<" "<<x.se<<'\n';
        }
        cout<<calc(0,0,1)<<'\n';
    }
}
