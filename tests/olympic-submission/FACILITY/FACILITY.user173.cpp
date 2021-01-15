#include<bits/stdc++.h>
#define ii pair<int,int>
#define pii pair<ii,int>
#define fi first
#define se second 
using namespace std;
const int N=1e4+7;
pii a[N];
int dp[N];
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
    cin>>a[i].fi.fi>>a[i].fi.se>>a[i].se;
    a[i].fi.se+=k+a[i].fi.fi;
    }
				//cout<<a[1].fi.fi;
    sort(a+1,a+n+1);
    dp[1]=a[1].se;
				//cout<<dp[1];
    for (int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],a[i].se);
        for (int j=i-1;j>=1;j--)
            if (a[i].fi.fi>=a[j].fi.se)
            dp[i]=max(dp[i],dp[j]+a[i].se);
    }
    cout<<dp[n];
}