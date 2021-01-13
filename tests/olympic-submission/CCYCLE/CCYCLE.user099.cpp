#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<ll>
#define sps <<" "<<
#define sp <<" "
#define el <<"\n"
const int mod=1e9+7;

int solve(int n,int l,int s,int t)
{
    if(l==0)
    {
        if(s==t) return 1;
        else return 0;
    }
    if(l==2&&s==t)
    {
        if(s%3==0) return 2;
        if(s%3==1) return 3;
        if(s%3==2) return 1;
    }
    if(l%2==1&&s==t) return 0;
    int m=3*n;
    if(t%3==2) return solve(n,l-1,s,t-1);
    if(t%3==0) return (solve(n,l-1,s,(t-2+m)%m)+solve(n,l-1,s,(t+1+m)%m))%mod;
    if(t%3==1) return (solve(n,l-1,s,(t+m-1)%m)+solve(n,l-1,s,(t+m+1)%m)+solve(n,l-1,s,(t+m+2)%m))%mod;
}

int main()
{
    int n,l,s,t;
    cin>>n>>l>>s>>t;
    int m=3*n;
    s%=m;t%=m;
    cout<<solve(n,l,s,t);
}
