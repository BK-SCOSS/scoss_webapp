#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int base=1e9+7;
const int N=152;
int n,m,l,s,t;
struct data
{
    int c[N][N];
    void build(bool tt)
    {
        if (tt==0)
        {
            for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                c[i][j]=0;
        }
        else
        {
            c[m][1]=c[1][m]=1;
            for (int i=1;i<=m;i++)
            if (i%3==0) c[i-2][i]=c[i+1][i]=1;
            else if (i%3==1) c[i-1][i]=c[i+2][i]=c[i+1][i]=1;
            else c[i-1][i]=1;
        }
    }
};
data operator * (data x,data y)
{
    data ans;
    ans.build(0);
    for (int k=1;k<=m;k++)
    for (int i=1;i<=m;i++)
    for (int j=1;j<=m;j++)
    {
        int t=((LL)x.c[i][k]*y.c[k][j])%base;
        ans.c[i][j]=(ans.c[i][j]+t)%base;
    }
    return ans;
}
data power(LL mu)
{
    data x;
    if (mu<=0)
    {
        x.build(0);
        return x;
    }
    x.build(1);
    if (mu==1) return x;
    data ans=power(mu/2);
    ans=ans*ans;
    if (mu%2==0) return ans;
    return ans*x;
}

int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>l>>s>>t;
    m=3*n;
    cout<<power(l).c[s][t];
    return 0;
}
