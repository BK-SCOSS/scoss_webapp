#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn
#define ll long long
#define Ntu "cntdiv"
#define pii pair<int,int>
#define st first
#define nd second

using namespace std;

int nt[1000008];
void snt()
{
    nt[1]=1;
    for(int i=2; i<=1000005; ++i)
        for(int j=1; i*j<=1000005; ++j) if (!nt[i*j]) nt[i*j]=i;
}

int n,rs,y,z;
int c,cc;
pii d[40];
int e[40];

void phantich(int x)
{
    while (x>1)
    {
        y=0;
        z=nt[x];
        while (x%z==0) ++y,x/=z;
        y*=2;
        d[++c]={z,y};
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen (Ntu".inp","r",stdin);
    //freopen (Ntu".out","w",stdout);
    int t;
    cin >> t;
    snt();
    int z,z1,x;
    while (t--)
    {
        cin >> n;
        c=cc=0;
        phantich(n);phantich(n+1);phantich(n+2);
        z=z1=1;
        fto(i,1,c) if (d[i].nd)
        {
            x=d[i].nd;
            fto(j,i+1,c) if (d[i].st==d[j].st) x+=d[j].nd,d[j].nd=0;
            e[++cc]=x;
        }
        fto(i,1,cc) z*=(e[i]+1),z1*=(e[i]/2+1);
        cout << (z-1)/2-z1+1 << '\n';
    }
    return 0;
}
