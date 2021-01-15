#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,q,t,u,ans;
    cin>>q;
    while(q--)
    {
        cin>>n;
        ans=0;
        t=n*(n+1)*(n+2);
        u=t*t;
        for(int i=1;i<t;i++)
            if(t%i!=0&&u%i==0) ans++;
        cout<<ans<<endl;
    }
}
