#include<bits/stdc++.h>
using namespace std;

int t,i,m,n,a[111],k,ans;

bool con(int x)
{
    int i;
    for (i=1;i<=m;i++) if (a[i]==x) return 1;
    return 0;
}

int main()
{
    cin>>t;
    while (t--)
    {
        ans=0;
        
        cin>>m;
        for (i=1;i<=m;i++) cin>>a[i];
        cin>>n;
        for (i=1;i<=n;i++)
        {
            cin>>k;
            if (con(k)==1) ans++;
        }
        cout<<ans;
    }
    
    return 0;
}
