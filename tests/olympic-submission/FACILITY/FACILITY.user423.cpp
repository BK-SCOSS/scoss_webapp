#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,k;
int a[1000005];
pair <int ,pair <int ,int > > b[1000005];
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        b[i]=mp(u+v+k,mp(v+k,w));
    }
    sort(b+1,b+n+1);
    int j=1;
    a[0]=0;
    for (int i=1;i<=1000000;i++)
    {
        a[i]=a[i-1];
        while (b[j].first==i && j<=n)
        {
            a[i]=max(a[i],a[i-b[j].second.first]+b[j].second.second);
            j++;
        }
    }
    cout<<a[1000000];
    return 0;
}
