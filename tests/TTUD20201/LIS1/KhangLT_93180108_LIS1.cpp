#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e5+2;
int n;
int s[N],a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],s[i]=a[i];
        sort(s+1,s+n+1);
        fill(f+1,f+n+1,0);
        int MAX=0;
        for(int i=1;i<=n;i++){

            int x = lower_bound(s+1,s+n+1,a[i]-1) - s;
            int y = lower_bound(s+1,s+n+1,a[i]) - s;
            if ( s[x] == a[i]-1 ) f[y] = f[x] + 1;
            else f[y] = 1;
            MAX=max(MAX,f[y]);
        }
        cout<<MAX;
    }
    return 0;
}
