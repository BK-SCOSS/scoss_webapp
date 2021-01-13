#include <iostream>
#include <cstdio>

using namespace std;

#define int long long
#define NMAX 1000006
#define xx first
#define yy second

int n,T,kq,cnt,dem[NMAX];
pair<int,int> hold[NMAX];
int prime[NMAX];

void make_prime()
{
    for(int i=2 ; i<NMAX-1 ; i++)
    if (prime[i]==0)
    {
        prime[i] = i;
        for(int j=i*i ; j<NMAX-1 ; j+=i)
            prime[j] = i;
    }
}

void update(int u)
{
    int u2 = u;
    while(u2!=1)
    {
        dem[ prime[u2] ]++;
        u2 /= prime[u2];
    }
}

int pow(int a,int b)
{
    if (b==0) return 1;
    int x = pow(a,b/2);
    x = x*x;
    if (b%2) x = x*a;
    return x;
}

void nhanhcan(int p,int s,int check)
{
    if (s>=T) return;
    if (p>cnt)
    {
        if (check) kq++;
        return;
    }
    for(int i=0 ; i<=hold[p].yy ; i++)
    {
        int x = pow(hold[p].xx,i);
        nhanhcan(p+1,s*x,check);
    }
    for(int i=hold[p].yy+1 ; i<=2*hold[p].yy ; i++)
    {
        int x = pow(hold[p].xx,i);
        nhanhcan(p+1,s*x,1);
    }
}

void solve()
{
    update(n);
    update(n+1);
    update(n+2);
    T = n*(n+1)*(n+2);
    cnt  =0;
    for(int i=1 ; i<NMAX-1 ; i++)
        if (dem[i])
        {
            cnt ++;
            hold[cnt].xx = i;
            hold[cnt].yy = dem[i];
            dem[i] = 0;
        }
    kq=0;
    nhanhcan(1,1,0);
    cout<<kq<<'\n';
}

main()
{
    //freopen("a.inp","r",stdin);
    make_prime();
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        solve();
    }
}
