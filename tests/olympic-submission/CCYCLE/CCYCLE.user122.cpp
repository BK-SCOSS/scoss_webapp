#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=3e4+2;
const int MOD=1e9+7;
const int bm=1;
int n,s,t,l;
int a[N][3];
int f[1002][N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

void create(int i){
    if ( i == 1 ) a[i][0] = n, a[i][1] = 2, a[i][2] = 3;
    else if ( i == n ) a[i][0] = n-2, a[i][1] = 1;
    else if ( i % 3 == 1 ) a[i][0] = i-1,a[i][1] = i+1, a[i][2] = i+2;
    else if ( i % 3 == 2 ) a[i][0] = i-1;
    else if ( i % 3 == 0 ) a[i][0] = i-2,a[i][1] = i+1;
    //if ( i < 5 ) cout<<i<<" "<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>l>>s>>t;
    n*=3;
    for(int i=1;i<=n;i++) create(i);
    f[0][s] = 1;
    for(int i=0;i<l;i++)
        for(int j=1;j<=n;j++){
            for(int k=0;k<3;k++)
                if ( a[j][k] ) f[i+1][a[j][k]] = (f[i+1][a[j][k]] + f[i][j] ) % MOD;
        }
//    for(int i=0;i<l;i++){
//        for(int j=1;j<=n;j++)
//            cout<<f[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<f[l][t];
}
