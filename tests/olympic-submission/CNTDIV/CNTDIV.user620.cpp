#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int N=1000005;
int kt[N],gt[N],c[N],gt2[N],c2[N];
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for (int i=1;i<N;i++) gt[i]=gt2[i]=c[i]=c2[i]=1;
    for (int i=2;i<N;i++) if (!kt[i])
    for (int j=i;j<N;j+=i)
    {
        kt[j]=1;
        int h=j,cnt=1;
        while (h%i==0)
        {
            h/=i;
            cnt++;
            if (i==2) c[j]++,c2[j]+=2;
        }
        gt[j]*=cnt;
        gt2[j]*=(cnt*2-1);
    }
    int q,n;
    cin>>q;
    while (q--)
    {
        int d1,d2;
        cin>>n;
        if (n%2==0)
        {
            d1=gt[n]*gt[n+1]*gt[n+2]*(c[n]+c[n+2]-1)/c[n]/c[n+2];
            d2=gt2[n]*gt2[n+1]*gt2[n+2]*(c2[n]+c2[n+2]-1)/c2[n]/c2[n+2];
        }
        else
        {
            d1=gt[n]*gt[n+1]*gt[n+2];
            d2=gt2[n]*gt2[n+1]*gt2[n+2];
        }
        //cout<<d1<<" "<<d2<<" ";
        d2--;
        d1--;
        d2/=2;
        cout<<d2-d1<<"\n";
    }
    return 0;
}
