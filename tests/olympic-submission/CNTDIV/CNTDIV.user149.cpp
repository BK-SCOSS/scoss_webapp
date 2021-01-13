#include <bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int n,rs,y,z,p[N+2],c,g,e[100];
pair<int,int> d[100];
void fraction(int x)
{
    while (x>1)
    {
        y=0;
        z=p[x];
        while (x%z==0)
        {
            y+=1;
            x/=z;
        }
        y*=2;
        c+=1;
        d[c]= {z,y};
    }
}
int main()
{
    for(int i=2; i<=N; ++i)
        for(int j=1; i*j<=N; ++j) if (p[i*j]==0) p[i*j]=i;
    int t;
    cin >> t;
    int z,z1,x;
    for(int o=1; o<=t; ++o)
    {
        cin >> n;
        c=0;
        g=0;
        fraction(n);
        fraction(n+1);
        fraction(n+2);
        z=z1=1;
        for(int i=1; i<=c; ++i) if (d[i].second)
            {
                x=d[i].second;
                for(int j=i+1; j<=c; ++j) if (d[i].first==d[j].first){
                        x+=d[j].second;
                        d[j].second=0;
                }
                e[++g]=x;
            }
        for(int i=1; i<=g; ++i)
        {
            z*=e[i]+1;
            z1*=e[i]/2+1;
        }
        cout << (z-1)/2-z1+1 << '\n';
    }
    return 0;
}
