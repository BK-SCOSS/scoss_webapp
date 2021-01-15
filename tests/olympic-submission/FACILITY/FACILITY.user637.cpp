#include<bits/stdc++.h>
#define int long long
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
const int mn=1e6+9;
int n,k;
struct data
{
    int s,d,r;
}a[mn];
int l[mn];
int cmp(data a,data b)
{
    if(a.d!=b.d)
        return a.d<b.d;
    if(a.s!=b.s)
        return a.s<b.s;
}
main()
{
    //#ifndef ONLINE_JUDGE
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    //#endif // ONLINE_JUDGE
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].s>>a[i].d>>a[i].r,
        a[i].d+=a[i].s-1;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        l[i]=a[i].r;
        data x={0,a[i].s-k,0};
        int j=lower_bound(a+1,a+1+n,x,cmp)-a-1;
        l[i]=max({l[i],a[i].r+l[j],l[i-1]});
    }
    cout<<l[n];

}
