#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e6+2;
const int MOD=1e9+7;
const int bm=1;
int n,k;
int s[N];
pair<ii,int> a[N];
long long f[N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].x.y>>a[i].x.x>>a[i].y;
        a[i].x.x += a[i].x.y + k;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i] = a[i].x.x;
//    cout<<endl;
//    for(int i=1;i<=n;i++) cout<<s[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=n;i++){
        int x = upper_bound(s+1,s+n+1,a[i].x.y)-s-1;
        f[i] = max(f[i-1], f[x]+a[i].y);
        //cout<<i<<" "<<x<<" "<<a[i].x.y<<" "<<a[i].y<<" "<<f[i]<<endl;
    }
    cout<<f[n];
}
