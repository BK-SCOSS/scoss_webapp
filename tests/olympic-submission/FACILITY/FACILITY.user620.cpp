#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define PII pair<int,int>
#define PPI pair<PII,int>
using namespace std;
const int N=1000005;
LL res,f[N];
int s[N],d[N],r[N],n,k;
vector<PPI> vt;
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i]>>d[i]>>r[i];
        d[i]+=s[i]+k;
        vt.push_back({{s[i],1},i});
        vt.push_back({{d[i],0},i});
    }
    sort(vt.begin(),vt.end());
    for (int i=0;i<vt.size();i++)
    {
        int j=vt[i].S;
        //cout<<j<<" "<<s[j]<<" "<<d[j]<<"\n";
        int tt=vt[i].F.S;
        if (tt==1) f[j]=res+r[j];
        else res=max(res,f[j]);
    }
    cout<<res;
    return 0;
}
