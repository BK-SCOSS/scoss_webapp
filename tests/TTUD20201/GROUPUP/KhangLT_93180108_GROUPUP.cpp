#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e5+2;
int n,t;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int m=0,MAX=0;
        long long kq=0;
        while(n!=1){
            m=0;
            MAX=0;
            for(int i=1;i<=n;i+=2){
                if ( i != n ) {
                    b[++m] = a[i]+a[i+1];
                    MAX=max(MAX,a[i]+a[i+1]);
                }
                else{
                    b[++m]=a[i];
                }
            }
            n=m;
            for(int i=1;i<=n;i++)
                a[i]=b[i];
            kq+=MAX;
        }
        cout<<kq<<endl;
    }
    return 0;
}
