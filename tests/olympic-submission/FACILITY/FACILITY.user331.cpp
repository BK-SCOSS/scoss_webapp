/*
    Author: FireDrake99
    Time created: 2020-10-16-21.14
*/

#include<bits/stdc++.h>
using namespace std;

//------------Constants----------------
#define ll long long int
#define N 1000010
//------------Variables----------------
struct point{
    ll s,d,r;
};
point a[N];
int n,k,t;
ll ans=0,te;
//------------Functions----------------
bool comp(point a, point b){
    if (a.s!=b.s) return a.s<b.s;
    if (a.d!=b.d) return a.d<b.d;
    return a.r>b.r;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//------------Input--------------------
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> a[i].s >> t >> a[i].r;
        a[i].d=a[i].s+t+k;
    }
//------------Work---------------------
    sort(a,a+n,comp);
//    for (int i=0; i<n; i++) cout << a[i].s << " " << a[i].d << " " << a[i].r << endl;
    for (int i=0; i<n; i++){
        te=0;
        for (int j=i-1; j>=0; j--)
            if (a[j].d<=a[i].s) te=max(te,a[j].r);
        a[i].r+=te;
        ans=max(ans,a[i].r);
    }
    cout << ans;
}
