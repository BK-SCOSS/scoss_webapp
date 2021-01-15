#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+5;
const int mod=1e9+7;
long long n,L,s,t;
long long dp[1005][3*nmax];
struct matran
{
    long long c[153][153];
    matran()
    {
        memset(c,0,sizeof c);
    }
};
matran operator*(matran a, matran b)
{
    matran res;
    for (int i=1;i<=3*n;i++)
        for (int j=1;j<=3*n;j++)
        {
            res.c[i][j]=0;
            for (int t=1;t<=3*n;t++)
                res.c[i][j]=(res.c[i][j]+a.c[i][t]*b.c[t][j])%mod;
        }
    return res;
}
matran mu(matran a, long long k)
{
    matran B;
    for (int i=1;i<=3*n;i++)
        B.c[i][i]=1;
    for ( ; k>0 ; a=a*a , k>>=1)
        if (k&1)
            B=B*a;
    return B;
}
void sub1()
{
    matran A,B;
    for (int i=1;i<=3*n;i++)
    {
        if (i==1)
        {
            A.c[2][1]=A.c[3][1]=A.c[3*n][1]=1;
            continue;
        }
        if (i==3*n)
        {
            A.c[1][i]=A.c[i-2][i]=1;
            continue;
        }
        if (i%3==0)
            A.c[i-2][i]=A.c[i+1][i]=1;
        if (i%3==1)
            A.c[i+1][i]=A.c[i-1][i]=A.c[i+2][i]=1;
        if (i%3==2)
            A.c[i-1][i]=1;
    }
    B.c[1][s]=1;
    A=mu(A,L);
    B=B*A;
    cout<<B.c[1][t]<<'\n';
}
void sub2()
{
    dp[0][s]=1;
    for (int i=1;i<=L;i++)
        for (int j=1;j<=3*n;j++)
        {
            if (j==1)
            {
                dp[i][1]=(dp[i-1][3*n]+dp[i-1][2]+dp[i-1][3])%mod;
                continue;
            }
            if (j==3*n)
            {
                dp[i][j]=(dp[i-1][j-2]+dp[i-1][1])%mod;
                continue;
            }
            if (j%3==0)
                dp[i][j]=(dp[i-1][j-2]+dp[i-1][(j+1)])%mod;
            if (j%3==1)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]+dp[i-1][j+2])%mod;
            if (j%3==2)
                dp[i][j]=dp[i-1][j-1];
        }
    cout<<dp[L][t]<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>n>>L>>s>>t;
    if (n<=50)
    {
        sub1();
        return 0;
    }
    if (L<=1000)
    {
        sub2();
        return 0;
    }
}
