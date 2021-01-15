#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e6+2;
const int MOD=1e9+7;
const int bm=1;
int n,m,dem;
vector<ii> f[N+2], thuaso;

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

void phantich(int n){
    for(int i=0;i<f[n].size();i++){
        int check=1;
        for(int j=0;j<thuaso.size()&&check;j++)
            if ( f[n][i].x == thuaso[j].x )
                thuaso[j].y += f[n][i].y, check=0;
        if ( check ) thuaso.pb(f[n][i]);
    }
}

void duyet(int i, long long x, long long t){

    if ( i == thuaso.size() ) return;
    for(int j=0;j<=thuaso[i].y*2;j++){
        if ( t%x ) dem+=(j>0);
        //cout<<i<<" "<<x<<" "<<t<<" "<<dem<<endl;
        duyet(i+1,x,t);
        //cout<<i<<" "<<x<<" "<<t<<" "<<dem<<endl;
        if ( t/thuaso[i].x < x ) break;
        x*=thuaso[i].x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    for(int i=2;i<=N;i++){
        if ( f[i].size() ) continue;
        for(int j=i;j<=N;j+=i){
            int h=0, k=j;
            while(k%i == 0) h++,k/=i;
            f[j].pb(ii(i,h));
        }
    }
    int t;
    cin>>t;
    while(t--){
        long long n,t=1;
        cin>>n,t=n*(n+1)*(n+2);
        thuaso.clear(),dem=0;
        for(int i=n;i<n+3;i++) phantich(i);
        duyet(0,1,t);
        cout<<dem<<endl;
    }
}
