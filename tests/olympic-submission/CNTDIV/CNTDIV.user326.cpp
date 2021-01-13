#include <bits/stdc++.h>
using namespace std;
int q;
int a[1011111];
bool ngto[1011111];
long long c[1011111];
vector < int > nto;
int sl_uoc(int x)
{
      if (x==1) return 0;
    if (ngto[x] == 0) return 1;

    int ans = 1;
    for (int i=0;i<nto.size();i++)
    {

            int sl = 1;
            while ( x % nto[i] == 0)
            {
                sl++;
                x /= nto[i];
            }
        ans *= sl;
        if (x == 1 ) return ans - 1;
    }
}

void input( int X )
{
     for (int i=0;i< nto.size();i++)
                {
                    while ( X%nto[i]==0)
                    {
                        c[i]+=1;
                        X/=nto[i];
                    }
                    if (X==1) return ;
                }
}

int get()
{
    long long res = 1;
    for (int i=0; i< nto.size();i++) res *= (c[i]+1);
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
   // freopen(".inp","r",stdin);
   // freopen(".out","w",stdout);
    cin>>q;
    for (int i=1;i<=q;i++)
    cin>>a[i];

    ngto[1] =1;
    for (int i=2;i<1011000;i++)
        if (ngto[i]==0)
        {
            nto.push_back(i);
            int j=2;
            while (i*j <= 1011000 )
            {
                ngto[i*j]=1;
                j++;
            }
        }

    for (int i=1;i<=q;i++)
    {
        memset(c,0,sizeof(c));
        int X= a[i];
        int XX = X+1;
        int XXX = XX+1;
        memset(c,0,sizeof(c));
        input(X);
        input(XX);
        input(XXX);
        long long res2  = get();
        input(X);
        input(XX);
        input(XXX);
        long long res = get();
        res = (res-1)/2;
        res -= res2 ;
        cout<<res+1 <<"\n";

    }



    return 0;
}
