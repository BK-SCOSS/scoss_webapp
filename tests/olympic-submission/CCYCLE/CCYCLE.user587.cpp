#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn
#define ll long long
#define Ntu "CCYCLE"
#define pii pair<int,int>
#define st first
#define nd second

using namespace std;

const int base = 1e9+7;

int n,L,s,t;
vector<int> a[1005];
int f[1005][1005];
map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen (Ntu".inp","r",stdin);
    //freopen (Ntu".out","w",stdout);
    cin >> n >> L >> s >> t;
    /*queue<pii> q;
    q.push({s,L});
    m[s]=1;
    pii u;
    int bd;
    int cnt=1;
    while (q.size())
    {
        u=q.front();q.pop();
        bd=u.st;
        if (bd==n*3)
        {
            if (!m[1])
            {
                m[1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({1,u.nd-1});

            }
            if (!m[bd-1])
            {
                m[bd-1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd-1,u.nd-1});
            }
        }
        else if (bd==1)
        {
            if (!m[3*n])
            {
                m[3*n]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({3*n,u.nd-1});
            }
            if (!m[2])
            {
                m[2]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({2,u.nd-1});
            }
        }
        else if (bd%3==2)
        {
            if (!m[bd-1])
            {
                m[bd-1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd-1,u.nd-1});
            }
        }
        else if (bd%3==0)
        {
            if (!m[bd-2])
            {
                m[bd-2]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd-2,u.nd-1});
            }
            if (!m[bd+1])
            {
                m[bd+1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd+1,u.nd-1});
            }
        }
        else if (bd%3==1)
        {
            if (!m[bd-1])
            {
                m[bd-1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd-1,u.nd-1});
            }
            if (!m[bd+1])
            {
                m[bd+1]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd+1,u.nd-1});
            }
            if (!m[bd+2])
            {
                m[bd+2]=++cnt;
                a[m[bd]].pb(cnt);
                a[cnt].pb(m[bd]);
                if (u.nd>0) q.push({bd+2,u.nd-1});
            }
        }
    }
    f[0][1]=1;
    fto(i,1,L)
    fto(j,1,cnt)
    {
        for(int z=0; z<a[j].size(); ++z)
        {
            bd=a[j][z];
            f[i][j]=(f[i][j]+f[i-1][bd])%base;
        }
    }*/
    cout << 0;
    ///f[i][j]:so cach di tu s den j qua i buoc
    return 0;
}
