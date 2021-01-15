#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
int n,q,a;
long long res;
int p[MAX];
int main()
{
   // freopen("cntdiv.inp","r",stdin);
  //  freopen("cntdiv.out","w",stdout);
    cin>>q;
     for(int h=1;h<=q;h++)
    {

        cin>>n;

        a = n;
        for(int i=2;a>1;i++)
        {
            while(a%i==0)
            {
                p[i]++;
                a=a/i;
            }
        }
        a=n+1;

        for(int i=2;a>1;i++)
        {
            while(a%i==0)
            {
                p[i]++;
                a=a/i;
            }
        }
        a=n+2;
        for(int i=2;a>1;i++)
        {
            while(a%i==0)
            {
                p[i]++;
                a=a/i;
            }
        }

        long long x=1,y=1;

        for(int i=2;i<=n+2;i++)
        {

            x= x*(p[i]+1);
            y= y*(p[i]*2+1);
        }
        for(int i=2;i<=n+2;i++) p[i] =0;

        cout<<y/2-(x-1)<<'\n';

    }
}
