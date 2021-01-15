#include<bits/stdc++.h>

using namespace std;

#define int long long

main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("CNTDIV.inp","r",stdin);
    //freopen("CNTDIV.out","w",stdout);
    int t;
    cin>>t;
    //cout<<"ok";
    while(t--)
    {
        int n;
        cin>>n;
        int kq=0;
        int res=n*(n+1)*(n+2);
        for(int i=2;i<res;i++)
        {
            if(res*res%i==0&&res%i!=0) kq++;
        }
        cout<<kq<<'\n';
    }
}
