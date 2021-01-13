#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
#define vull vector<ull>
#define pb push_back

int main()
{
    int t;cin>>t;
    ull a,b,tmp;
    vull ans(0);
    while(t--)
    {
        cin>>a>>b;
        ans.clear();
        while(a>0&&b>0)
        {
            tmp=a%10+b%10;
            a/=10;b/=10;
            if(tmp>=10) a++;
            ans.pb(tmp%10);
        }
        if(a!=0) ans.pb(a);
        if(b!=0) ans.pb(b);
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
        cout<<endl;
    }
}
