#include<bits/stdc++.h>
using namespace std;

int t,i,j,n,a[101010],ans,q;

int main()
{
    cin>>t;
    while (t--)
    {
        ans=0;
        
        cin>>n;
        for (i=1;i<=n;i++) cin>>a[i];
        
        while (n>1)
        {
            q=0;
            
            for (i=1;i<=n/2;i++) a[i]=a[i*2-1]+a[i*2];
            if (n%2==0)
            {
                n/=2;
                for (i=1;i<=n;i++) q=max(q,a[i]);
                ans+=q;
            }
            else
            {
                n=(n+1)/2;
                a[n]=a[n*2-1];
                for (i=1;i<n;i++) q=max(q,a[i]);
                ans+=q;
            }
        }
        
        cout<<ans<<endl;
    }
}
