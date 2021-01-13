#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define maxn 30002



int n,l,s,t;

vector <int> a[maxn];

long long f[1002][maxn];

void pu(int x,int y)
{
    a[x].push_back(y);
    a[y].push_back(x);
}

int main()
{
  //  freopen("A.INP","r",stdin);
  //  freopen("A.OUT","w",stdout);

    cin>>n>>l>>s>>t;

    pu(1,2);pu(1,3);pu(1,3*n);

    for(int i=1;i<=n-1;i++)
    {
        pu(3*i+1,3*i);
        pu(3*i+1,3*i+2);
        pu(3*i+1,3*i+3);
    }

    f[0][s]=1;

    for(int i=1;i<=l;i++)
        for(int j=1;j<=3*n;j++)
    {
        for(int k=0;k<a[j].size();k++)
        {
            int u=a[j][k];
            f[i][j]=(f[i][j]+f[i-1][u])%1000000007;
        }
    }

    cout<<f[l][t];



}
