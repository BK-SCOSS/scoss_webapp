#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e5+2;
int n,m,t;
int a[N],b[N],d[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        b[m+1]=-1;
        int j=1,dem=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                if ( a[i] == a[j] ) a[j] = -1;
        }
//        int tong=0;
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<" ",tong+=(a[i]>0);
//        cout<<endl<<tong<<endl;
//        for(int i=1;i<=n;i++){
//            while( b[j] < a[i] && j < m ) j++;
//            if ( a[i] == b[j] ) dem++,j++;
//        }
        fill(d+1,d+m+1,0);
        for(int i=1;i<=n;i++)
            for(int k=1;k<=m;k++)
                if ( a[i] == b[k] && !d[k] && a[i] > 0 ) {
                    d[k]=1;
                    dem++;
                    break;
                }
        cout<<dem<<endl;
    }

    return 0;
}
