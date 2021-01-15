#include <iostream>
#include <cstdio>

using namespace std;


#define int long long
#define NMAX 10004
#define LMAX 1003
#define MOD 1000000007

int n,L,s,t,kq;
int f[3*NMAX][LMAX];

int tinh(int u,int cnt)
{
    if (u==0) u = 3*n;
    if (u==3*n+1) u = 1;
    if (cnt==L)
        return (u==t);
    if (f[u][cnt]!=-1) return f[u][cnt];
    int tmp = 0;
    if (u%3==1)
    {
        tmp+=tinh(u-1,cnt+1);
        tmp+=tinh(u+1,cnt+1);
        tmp+=tinh(u+2,cnt+1);
    }
    if (u%3==0)
    {
        tmp+=tinh(u-2,cnt+1);
        tmp+=tinh(u+1,cnt+1);
    }
    if (u%3==2)
    {
        tmp+=tinh(u-1,cnt+1);
    }
    tmp%=MOD;
    f[u][cnt] = tmp;
    return tmp;
}

void solve()
{
    for(int i=1 ; i<=3*n ; i++)
        for(int j=0 ; j<=L ; j++)
            f[i][j] = -1;
    int kq = tinh(s,0);
    cout<<kq;
}

main()
{
    //freopen("a.inp","r",stdin);
    cin>>n>>L>>s>>t;
    solve();
}
