#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000006;
int n,k;
struct data{
    int a;
    int b;
    int r;

}x[MAX];
int a[MAX],c[MAX],d[2*MAX];
long long res;
long long f[MAX];
long long bit[2*MAX];
bool cmp(data x,data y){
    if(x.a<y.a) return 1;
    if(x.a == y.a && x.b < y.b ) return 1;
    return 0;

}
long long get(int x)
{
    long long res =0;
    for(;x>0;x-=x&(-x))
        res= max (res, bit[x]);
    return res;
}
void update(int x,long long val)
{
    for(;x<= 2*n ; x+=x&(-x))
        bit[x] = max (bit[x], val);
}
int main()
{
   // freopen("facility.inp","r",stdin);
   // freopen("facility.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,h;
        cin>>u>>v>>h;
        x[i].a = u;
        x[i].b = u+v-1;
        x[i].r = h;


    }
    sort(x+1,x+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=x[i].a;
        c[i]= x[i].b + k+1;
        d[++cnt] = a[i];
        d[++cnt] = c[i];

    }
    sort(d+1,d+cnt+1);
    for(int i=1;i<=n;i++)
        a[i] = lower_bound(d+1,d+cnt+1,a[i]) - d;
    for(int i=1;i<=n;i++)
        c[i] = lower_bound(d+1,d+cnt+1,c[i]) - d;
    for(int i=1;i<=n;i++)
    {
        f[i]= get(a[i])+ x[i].r;
        update(c[i],f[i]);
    }
    for(int i=1;i<=n;i++)
        res= max(res,f[i]);
    cout<<res;

}

